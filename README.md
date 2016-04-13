# interaction-graphs
Attempt to create and analyze interaction graph by studying the composition of general n functions

An attempt to model biological cells and their interactions as a directed graph and to study their properties.
(JAVA) The base model comprises of getting the input in the form of (n) boolean functions. After studying
functional decomposition of a function in respect to other given functions, model an interaction graph that
depicts the flow between any two functions. The interaction graph is further broke down into subsets
which include the graphs with complete edges as well as the graph with at least a single cycle. The inputs
are the combinations of n functions. Ulterior motive is to generalize the results for n functions.


Compile with : (in parent directory)
  $ time make nodes=N
  
  where N is the Nodes i.e simultaneous boolean functions
  
  
  Modify the comb.py file in /sources/comb.py for individual results, brute force results and for special cases.
  Read me has been updated for Nodes = 1, 2, 3, 4
  
  For 4, the brute force will take an estimate 1600 years on a single i5 multicore CPU, thus extrapolation had to be required to reach a common ground for N = 4
