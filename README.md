# simple-Neural-Network-library-in-C

A simple neural network implementation in pure C

## Documentation

### Structs
|         Network        |        Layer         |      Node      |
|         -------        |        -----         |      ----      |
| int *networkLayerSizes | Node *node           | double value   |
| int numberOfLayers     | char *activationFunc | double *weight |
| int inputSize          |                      | double bias    |
| int outputSize         |                      | double error   |
| Layer *layer           |                      | double dvalue  |

### Functions

| Name | Description |
| ---- | ----------- |
| void initNetwork(Network *net,int networkSize, int* nlayerSizes, char* activationFunc[]) | Initializes Network struct's fields |
| double randomD(double min, double max) | Generates a random double in range [min,max] |
| int max(int arr[], int n) | Returns the max value from array arr. n is the lenght of arr |
| void randomizeWeights(Network *net) | Initializes randomly Network's weights |
| void forwardPass(Network *net, double *input) | Pushes the inputs forward to the Network |
| void backProp(Network *net, double *target) | Back propagates the output error and calculates the error of each neuron |
| void updateWeights(Network *net,double lr) | Updates the weights based on calculated errors |
| double mse(Network n, double target[]) | Calculates mean squared error |
| void saveModel(Network *net,char *filename) | Saves Network architecture and weights in a text file |
| void loadModel(Network *n, char *filename) | Loads Network architecture and weights from a text file |
	
| Activation Functions | Error Functions |
| -------------------- | --------------- |
| sigmoid | mean squared error |
| tanH |
| ReLu |
	
Run Example
============
Train the Network in XOR problem and save the trained network in a text file

	gcc trainXor.c -o trainxor -lm && ./trainxor
	
Load Network from the text file and test it

	gcc testXor.c -o testxor -lm && ./testxor
	
