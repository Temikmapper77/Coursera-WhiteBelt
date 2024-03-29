#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        }
        if (operation == '-'){  // operation == '-'
            return source_value - value;
        }
        if (operation == '*') {
            return source_value * value;
        }
        if (operation == '/') {
            return source_value / value;
        }
        return 0;
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        }
        else if (operation == '-') {
            operation = '+';
        }
        else if (operation == '*') {
            operation = '/';
        }
        else {
            operation = '*';
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({ operation, value });
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {

    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    
    return function;
}

double ComputeImageWeight(const Params& params, 
                          const Image& image) {

    Function function = MakeWeightFunction(params, image);

    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {

    Function function = MakeWeightFunction(params, image);
    function.Invert();

    return function.Apply(weight);
}