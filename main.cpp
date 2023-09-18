#include <cstdlib>
#include <dhmodel.h>
#include <iostream>

#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_CLEAR "\x1B[0m"

int main(int argc, char ** argv)
{
    if (argc != 7)
    {
        std::cout << COLOR_RED << "error: " << COLOR_CLEAR << "need 6 'theta' values" << std::endl;
        return 1;
    }

    dhmodel::DHModel dh_model = {
      dhmodel::DHChainElement(0, 0, 0.21, 90),      dhmodel::DHChainElement(0, -0.8, 0.193, 0),
      dhmodel::DHChainElement(0, -0.598, -0.16, 0), dhmodel::DHChainElement(0, 0, 0.25, 90),
      dhmodel::DHChainElement(0, 0, 0.25, -90),     dhmodel::DHChainElement(0, 0, 0.25, 0),
    };

    for (int i = 0; i < 6; ++i)
    {
        dh_model[i].set_theta(::atof(argv[i + 1]));
    }

    Eigen::Vector4d start;
    start << 0, 0, 0, 1;
    std::cout << COLOR_GREEN << "Result point location (x, y, z, w):\n"
              << COLOR_CLEAR << dh_model.calc_transform(start) << std::endl;

    return 0;
}