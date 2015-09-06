/*
 * neural_network.cc
 * Copyright (C) 2015 Sean Kirmani <sean@kirmani.io>
 *
 * Distributed under terms of the MIT license.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

// calculate a random number where:  a <= rand < b
double random(double a, double b) {
    return (b - a) * ((double) rand() / RAND_MAX) + a;
}

/**
 * Default fill: 0.0
 */
std::vector<std::vector<double>> make_matrix(unsigned int I, unsigned int J, double fill=0.0) {
    return std::vector<std::vector<double>>(I, std::vector<double>(J, fill));
}

double sigmoid(double x) {
    return tanh(x);
}

double dsigmoid(double y) {
    return 1.0 - y * y;
}

class NN {
        unsigned int ni;
        std::vector<unsigned int> nh;
        unsigned int no;
        unsigned int nl;
        std::vector<std::vector<double>> activation;
        std::vector<std::vector<std::vector<double>>> weights;
        std::vector<std::vector<std::vector<double>>> change;
    public:
        NN (unsigned int num_inputs, std::vector<unsigned int> hidden_layers, unsigned int num_outputs) {
            ni = num_inputs + 1;
            nh = hidden_layers;
            no = num_outputs;
            nl = hidden_layers.size() + 2;

            std::vector<double> activation_layer;
            for (int i = 0; i < ni; i++) {
                activation_layer.push_back(1.0);
            }
            activation.push_back(activation_layer);
            for (int i = 0; i < nl - 2; i++) {
                activation_layer = std::vector<double>();
                for (int j = 0; j < nh.at(i); j++) {
                    activation_layer.push_back(1.0);
                }
                activation.push_back(activation_layer);
            }
            activation_layer = std::vector<double>();
            for (int i = 0; i < no; i++) {
                activation_layer.push_back(1.0);   
            }
            activation.push_back(activation_layer);

            for (int i = 1; i < nl; i++) {
                weights.push_back(make_matrix(activation.at(i - 1).size(), activation.at(i).size()));        
            }

            for (int i = 0; i < weights.size(); i++) {
                for (int row = 0; row < weights.at(i).size(); row++) {
                    for (int col = 0; col < weights.at(i).at(0).size(); col++) {
                        weights.at(i).at(row).at(col) = random(-0.2, 0.2);
                    }
                }
            }

            for (int i = 1; i < nl; i++) {
                change.push_back(make_matrix(activation.at(i - 1).size(), activation.at(i).size()));        
            }
        }
        
        
};
    
void demo() {
    // Teach network XOR function
    std::vector<std::vector<std::vector<double>>> pattern = {
        {{0.0, 0.0}, {0.0}},
        {{0.0, 1.0}, {1.0}},
        {{1.0, 0.0}, {1.0}},
        {{1.0, 1.0}, {0.0}}
    };
    
    // create a neural network with two input, two hidden, and one output nodes
    std::vector<unsigned int> hidden_layers = {2, 2};
    NN n = NN(2, hidden_layers, 1);

    printf("%f", random(-0.2, 0.2));
}

int main() {
    srand(time(NULL));
    demo();
    return 0;
}
