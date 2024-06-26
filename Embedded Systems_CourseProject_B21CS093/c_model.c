
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <stm32f429xx.h>


double relu(double x);
void sigmoid(double *x, int size);
void forward_pass(double *input, double *weights, double *biases, double *output);
void GPIO_INIT(void);

// Define GPIO_INIT function

// void GPIO_INIT(void){
// 	RCC->AHB1ENR |= 0x40 ;
// 	GPIOG->MODER |= 0x14000000 ;
// 	GPIOG->ODR |= 0x0;
// }

// Define the neural network architecture
#define INPUT_SIZE 6
#define HIDDEN1_SIZE 16
#define HIDDEN2_SIZE 16
#define OUTPUT_SIZE 1



// ReLU activation function
double relu(double x) {
    return fmax(0, x);
}

// Sigmoid activation function
void sigmoid(double *x, int size) {
    for (int i = 0; i < size; i++) {
        x[i] = 1 / (1 + exp(-x[i]));
    }
}


// Forward pass function
void forward_pass(double *input, double *weights, double *biases, double *output) {
    // Hidden layer 1 with ReLU activation
    double hidden1[HIDDEN1_SIZE];
    for (int i = 0; i < HIDDEN1_SIZE; i++) {
        double neuron = biases[i];
        for (int j = 0; j < INPUT_SIZE; j++) {
            neuron += input[j] * weights[i * INPUT_SIZE + j];
        }
        hidden1[i] = relu(neuron);
    }

    // for(int i = 0 ; i < HIDDEN1_SIZE; i++){
    //     printf("%lf ",hidden1[i]);
    // }

    // Hidden layer 2 with ReLU activation
    double hidden2[HIDDEN2_SIZE];
    for (int i = 0; i < HIDDEN2_SIZE; i++) {
        double neuron = biases[HIDDEN1_SIZE + i];
        for (int j = 0; j < HIDDEN1_SIZE; j++) {
            neuron += hidden1[j] * weights[(INPUT_SIZE + i) * HIDDEN1_SIZE + j];
        }
        hidden2[i] = relu(neuron);
    }

    // Output layer with Softmax activation
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double neuron = biases[HIDDEN1_SIZE + HIDDEN2_SIZE + i];
        for (int j = 0; j < HIDDEN2_SIZE; j++) {
            neuron += hidden2[j] * weights[(INPUT_SIZE * HIDDEN1_SIZE + HIDDEN1_SIZE * HIDDEN2_SIZE + (i * HIDDEN2_SIZE + j))];
        }
        output[i] = neuron; // Softmax activation is applied later
    }

    // Apply softmax activation to output layer
    sigmoid(output, OUTPUT_SIZE);
}





int main() {
		// GPIO_INIT();
	printf("%s", "Hello World!");
    // Allocate memory for weights and biases 
    // double *weights = (double *)malloc((INPUT_SIZE * HIDDEN1_SIZE + HIDDEN1_SIZE * HIDDEN2_SIZE + HIDDEN2_SIZE * OUTPUT_SIZE) * sizeof(double));
    // double *biases = (double *)malloc((HIDDEN1_SIZE + HIDDEN2_SIZE + OUTPUT_SIZE) * sizeof(double));
    double weights[] = {-0.106195986,0.19050683,-0.0076747662,0.45584568,-0.5457211,0.20622511,0.3731852,0.23855506,-0.45144138,-0.5421999,-0.36439618,0.052236825,-0.2471005,-0.21368611,-0.49593905,0.4778549,-0.08836889,-0.28243247,-0.15117711,-0.030294776,-0.42770207,-0.2125557,0.006822169,0.009898186,-0.10151334,0.08162428,-0.20496263,0.24813871,0.18320057,0.45088086,0.10975808,-0.43692788,0.11770433,-0.3547566,-0.17927429,-0.51420003,-0.36357498,-0.054835495,0.5097884,-0.4474536,-0.12913145,-0.49237955,0.32557246,0.0032457632,-0.18326132,-0.23141289,-0.14015724,-0.31010425,0.15927312,-0.007431914,0.36927593,0.066418186,0.2103948,-0.09330259,0.27757674,0.26755986,0.16958721,-0.00630884,-0.12266149,-0.10332619,0.015587407,-0.46541294,-0.16533293,-0.41821074,0.5276712,0.13332808,-0.44474497,0.52340126,-0.19801329,0.133546,-0.29481843,-0.4127229,0.280354,0.013674803,-0.11363233,0.39516902,-0.13096999,0.0020809886,0.13481408,-0.2338116,-0.2409329,0.094123565,-0.021067329,0.02633278,-0.24195677,0.2230676,0.3525944,0.3415526,0.3612685,-0.012981035,-0.17116149,0.44119352,-0.4373552,0.35446215,-0.02467154,-0.47867355,-0.11954273,0.14245573,0.35968593,-0.2864796,0.091099165,-0.14978677,0.1717445,0.038859986,-0.36422998,0.2003931,-0.002278775,-0.11336361,-0.15098418,-0.11955991,-0.025773086,-0.12094032,0.24857625,-0.046744894,0.21246424,0.21712229,-0.18994112,-0.37346268,-0.1945694,-0.3421407,0.19443764,0.3068161,0.046615046,-0.20189556,0.38090757,0.016796973,0.42202398,0.040510383,0.0052772565,-0.10577195,0.17615017,0.036138564,-0.079188034,0.27019015,-0.20071705,0.29846463,0.33331925,0.35923168,-0.27172673,-0.31553122,-0.25965065,-0.1854892,0.34486544,0.23931389,0.29944965,0.14930937,0.14239296,0.19185367,0.4068739,0.31567612,-0.19447726,-0.071576744,-0.085508436,-0.27485168,0.14007774,0.22411385,0.119235665,-0.008901,-0.40413302,-0.035262465,0.3507208,0.16911753,0.1527985,0.29096302,0.3383495,0.02375409,-0.3227557,0.12642342,-0.057901736,-0.050846487,0.37539783,0.33053687,-0.28072405,0.18707272,0.14179897,-0.3746256,-0.29193088,-0.1402635,0.3737881,-0.09739798,-0.1448462,0.07477638,0.05416007,0.053502016,0.23693196,-0.18116422,-0.22849669,-0.3257179,0.39859176,0.37446094,0.28711408,0.30975202,-0.24938646,-0.12758043,-0.4129408,-0.2049929,-0.1389391,-0.0981991,0.15708224,0.37435135,-0.15710914,0.26141465,-0.15310085,0.2247267,0.3238435,0.17029327,0.113911584,-0.14572173,-0.23081467,0.1451325,0.24452987,-0.39441922,-0.18732093,-0.4111717,-0.1417739,-0.13081416,0.06908637,0.21594632,0.23866083,0.38598418,0.2195486,-0.33062053,0.084181905,-0.20324366,-0.15958315,-0.14524046,0.18978891,-0.25327003,0.38895163,-0.2708991,-0.022272825,0.01010415,-0.036861956,-0.40331188,-0.394555,-0.123889536,-0.20691654,-0.022323817,-0.0042211115,-0.3816212,-0.13750547,0.3490398,-0.12275866,-0.113298744,-0.011730474,0.41931596,0.09610929,0.3036909,0.32511327,-0.042585842,-0.053082045,-0.11782961,-0.46768388,-0.18834521,-0.114238985,0.028885217,0.32812285,-0.2906259,0.39958456,0.19963142,-0.090689376,0.10083869,-0.18339172,-0.021775482,0.27524891,-0.23505643,-0.28451583,0.22773659,-0.033178624,-0.004142904,0.08504096,0.2871385,-0.25070465,-0.13611709,0.4121181,-0.20992202,-0.019202385,-0.18663476,-0.3205155,0.29036945,0.14513065,-0.4771791,0.1715135,-0.0026276112,-0.32380593,-0.120008916,0.15309343,-0.33669794,0.07775705,0.38158044,-0.3956138,-0.30996796,0.13507769,-0.05705908,-0.32087362,0.0018054445,-0.30598125,-0.24127473,0.16330269,-0.22497943,0.03716855,0.098937854,-0.024976661,0.024821805,-0.008124938,0.23917396,-0.01049158,0.08579925,-0.25489157,0.31298646,-0.24252301,-0.2284326,0.22421874,-0.370104,-0.05111575,-0.41368055,0.20477746,-0.31389716,-0.4083839,0.16388857,-0.29697472,-0.057907823,-0.03879115,-0.41462594,-0.24905817,0.30262265,-0.08162778,0.036331784,0.31787187,0.4243968,0.104598895,-0.08570961,0.43593505,-0.029397536,-0.35934883,-0.009079037,-0.37394512,-0.03661573,-0.0366275,-0.09842375,-0.0062637627,-0.10987949,0.26752475,-0.40222868,-0.35450506,-0.060099125,0.044384807,-0.279714,0.1937271,0.16519597,-0.39903593,-0.20598142,-0.14370415,-0.57049,0.42365223,0.4539219,0.32312244,0.16399185,0.37503946,-0.32922244,0.553236,-0.41865698,0.5258432,0.21322827,-0.21298094,-0.22107999,0.07729797,0.17811847}; 

    double biases[] = {-0.0601184,-0.041996114,0.0,0.0,0.029624946,0.0,-0.0046879994,0.048193086,-0.04120425,0.014302336,0.047989655,0.011425765,-0.002343602,0.011388646,0.012025022,0.03197183,-0.05553453,-0.034606915,0.03486919,0.0,0.00014112017,0.035352986,0.035842035,-0.034355722,0.0,-0.041026406,-0.0049635675,-0.04341823,-0.028324626,-0.03574536,0.039383046,0.0,0.034754723};



    double input[INPUT_SIZE] = {85.0,64.0,59.0,32.0,23.0,0.0}; // Assuming you have some input data
    double output[OUTPUT_SIZE];

    // Read weights from file
    // FILE *weights_file = fopen("weights.txt", "r");
    // if (weights_file == NULL) {
    //     fprintf(stderr, "Error opening weights file\n");
    //     return 1;
    // }
    // for (int i = 0; i < INPUT_SIZE * HIDDEN1_SIZE + HIDDEN1_SIZE * HIDDEN2_SIZE + HIDDEN2_SIZE * OUTPUT_SIZE; i++) {
    //     fscanf(weights_file, "%lf", &weights[i]);
    // }
    // fclose(weights_file);
    

    // Read biases from file
    // FILE *biases_file = fopen("biases.txt", "r");
    // if (biases_file == NULL) {
    //     fprintf(stderr, "Error opening biases file\n");
    //     return 1;
    // }
    // for (int i = 0; i < HIDDEN1_SIZE + HIDDEN2_SIZE + OUTPUT_SIZE; i++) {
    //     fscanf(biases_file, "%lf", &biases[i]);
    // }
    // fclose(biases_file);
    
    // Read input from file
    // FILE *input_file = fopen("input.txt", "r");
    // if (input_file == NULL) {
    //     fprintf(stderr, "Error opening input file\n");
    //     return 1;
    // }
    // for (int i = 0; i < INPUT_SIZE; i++) {
    //     fscanf(input_file, "%lf", &input[i]);
    // }
    // fclose(input_file);

    
    // Perform forward pass
    forward_pass(input, weights, biases, output);

    // Output the result
    printf("Output:\n");
    for (int i = 0; i < OUTPUT_SIZE; i++) {
       printf("%lf ", output[i]);
    }
    printf("\n");
		// if(output[0] > output[1]){
		// 		GPIOG->ODR = 0x2000;
		// }
		// else{
		// 	  GPIOG->ODR = 0x4000;
		// }
    // Free allocated memory
    free(weights);
    free(biases);
		// while(1){}
    return 0;
}


