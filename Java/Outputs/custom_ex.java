import java.io.*;

@SuppressWarnings("serial")

class ExceededLimit extends Exception{
    int value;

    public ExceededLimit(int value){
        this.value= value;
    }

    public String toString(){
        return "Not accepted for input: "+value;
    }
}

class Value{

    private void get_value() throws IOException,ExceededLimit {
        System.out.print("Enter a value: ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int val = Integer.parseInt(br.readLine());

        if (val>10)
            throw new ExceededLimit(val);
    }

    public static void main(String args[]){

        Value obj = new Value();
        while(true){
            try{
                obj.get_value();
            }
            catch (ExceededLimit | IOException e1){
                System.out.println(e1);
            }
        }

    }
}