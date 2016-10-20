#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <numeric>
#include <cmath>
using namespace std;

class Neuron;
typedef vector<Neuron> Layer;

struct Connection{
        double weight;
        double deltaWeight;
};

// ********Class Neuron ****************
class Neuron{
public:
    // How many output weights will neuron have
    Neuron(int numOutputs, int myIndex);
    void feedForward(const Layer &prevLayer);
    void setOutputValue(double val){
        m_outputVal = val;
    }
    double getOutputValue(void) const{
        return m_outputVal;
    }
    void calcOutGradient(double targetVal);
    void calcHiddenGradient(const Layer &nextLayer);
    void updateInputWeights(Layer &prevLayer);

private:
    static double activationFn(double x);
    static double activationFnDerivative(double x);
    static double randomWeight(void){
        return rand() / double(RAND_MAX);
    }
    double sumDow(const Layer &nextLayer) const;
    double m_outputVal;
    static double eta;  //overall net training rate
    static double alpha; //multiplier of last weight change momentum
    int m_myIndex;
    double m_gradient;
    vector<Connection> m_outputWeights;
};

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;

Neuron::Neuron(int numOutputs, int myIndex){
    // Constructor for the neuron
    for (int con = 0; con < numOutputs; con++){
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
    }
    m_myIndex = myIndex;
}

void Neuron::feedForward(const Layer &prevLayer){
    // Neuron's feed forward
    double sum = 0.0;

    for (int n = 0; n < prevLayer.size(); ++n){
        sum += prevLayer[n].getOutputValue() * prevLayer[n].m_outputWeights[m_myIndex].weight;
    }
    // Now apply the activation function
    m_outputVal = Neuron :: activationFn(sum);
}

double Neuron::activationFn(double x){
    // Use a sigmoid curve
    return tanh(x);
}

double Neuron::activationFnDerivative(double x){
    // Use a sigmoid curve
    return 1 - x * x;
}

void Neuron::calcOutGradient(double targetVal){
    double delta = targetVal - m_outputVal;
    m_gradient = delta * Neuron :: activationFnDerivative(m_outputVal);
}

void Neuron::calcHiddenGradient(const Layer &nextLayer){
    double dow = sumDow(nextLayer);
    m_gradient = dow * Neuron :: activationFnDerivative(m_outputVal);
}

double Neuron::sumDow(const Layer &nextLayer) const{
    double sum = 0.0;
    // sum error contributions
    for (int n = 0; n < nextLayer.size(); n++)
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    return sum;
}

void Neuron::updateInputWeights(Layer &prevLayer){
    // The weights to be updates are in the Connection container
    // in the neurons in the preceding layer
    for (int n = 0; n < prevLayer.size(); n++){
        Neuron &neuron = prevLayer[n];
        double oldDeltaWt = neuron.m_outputWeights[m_myIndex].deltaWeight;

        double newDeltaWt =
                    // Individua; imp modified by gradient and train rate
                    eta * neuron.getOutputValue() * m_gradient
                    // Also add momentum = fraction of prev delta weight
                    + alpha * oldDeltaWt;
        neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWt;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWt;
    }
}

// ***********CLASS NET***************
class Net{
    // A class that implements neural net;
public:
    Net(const vector<int> &topology);
    void feedForward(const vector<double>& inputVals);
    void backProp(const vector<double>& targetVals);
    void getResults(vector<double>& resultsVals) const;

private:
    vector<Layer> m_layers;
    double m_error;
    double m_recentAvg;
    double m_recentAvgSmoothFactor;
};

Net::Net(const vector<int> &topology){
    /* Constructor that takes in an array whose size is the number of layers whose ith elemmis the number of neurons at that layer
    */
    int numLayers = topology.size();
    for (int layer = 0; layer < numLayers; layer++){
        m_layers.push_back(Layer());
        int numOutputs = topology.size() - 1 ? 0 : topology[layer + 1];
        // We have made a layer. Let's add neurons
        for (int neuron = 0; neuron <= topology[layer]; neuron++)
            // Create a new neuron and append
            m_layers.back().push_back(Neuron(numOutputs, neuron));
    }
    // force the bias node's output value to 1
    m_layers.back().back().setOutputValue(1.0);
}

void Net::feedForward(const vector<double>& inputVals){
    // feeds forward the input vals
    assert(inputVals.size() == m_layers[0].size() -1);
    for (int i = 0; i < inputVals.size(); i++){
        m_layers[0][i].setOutputValue(inputVals[i]);
    }
    // Now do forward propagation
    // Loop through each neuron in each Layer
    for (int layer = 1; layer < m_layers.size(); layer++){
        Layer &prevLayer = m_layers[layer -1];
        for (int n = 0; n < m_layers[layer].size(); n++){
            m_layers[layer][n].feedForward(prevLayer);
        }
    }
}

void Net::backProp(const vector<double>& targetVals){
    // Calculate overall net error: RMS error
    Layer &outputLayer = m_layers.back();
    m_error = 0.0;

    for (int n = 0; n < outputLayer.size(); n++){
        double delta = targetVals[n] - outputLayer[n].getOutputValue();
        m_error += delta * delta;
    }
    m_error /= outputLayer.size();
    m_error = sqrt(m_error);

    // implement a recent avg measurement
    m_recentAvg = (m_recentAvg * m_recentAvgSmoothFactor * m_error);
    m_recentAvg /= m_recentAvgSmoothFactor;

    // Calculate output layer gradients
    for (int n = 0; n < outputLayer.size(); n++){
        outputLayer[n].calcOutGradient(targetVals[n]);
    }
    // Calculate hidden layer gradients
    for (int h = m_layers.size() -2; h > 0; h--){
        Layer &hidden = m_layers[h];
        Layer &nextLayer = m_layers[h + 1];
        for (int n = 0; n < hidden.size(); n++)
            hidden[n].calcHiddenGradient(nextLayer);

    }

    // For all layers from output to first, update weights
    for (int layerN = m_layers.size() -1; layerN > 0; layerN --){
        Layer &layer = m_layers[layerN];
        Layer &prevLayer = m_layers[layerN -1];
        for (int n = 0; n < layer.size(); n++)
            layer[n].updateInputWeights(prevLayer);
    }
}

void Net::getResults(vector<double>& resultsVals) const{
    // Clears out the container and loops through all neurons in outputs layer and moves them to resultsVals
    resultsVals.clear();
    for (int n = 0; n < m_layers.back().size() -1; n++){
        resultsVals.push_back(m_layers.back()[n].getOutputValue());
    }
}

int main(){

    // e.g {3, 2, 1};
    vector<int> topology{3, 2, 1};
    Net newNet(topology);

    vector<double> inputVals;
    newNet.feedForward(inputVals);

    vector<double> targetVals;
    newNet.backProp(targetVals);

    vector<double> resultsVals;
    newNet.getResults(resultsVals);

    return 0;
}
