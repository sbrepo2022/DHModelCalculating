#ifndef DHMODEL
#define DHMODEL

#define _USE_MATH_DEFINES

#include <Eigen/Dense>
#include <cmath>
#include <initializer_list>


namespace dhmodel
{

constexpr inline double deg_to_rad(double deg);


class DHChainElement
{
private:
    double theta;
    double a;
    double d;
    double alpha;

public:
    DHChainElement(double theta, double a, double d, double alpha);
    void set_theta(double theta);
    Eigen::Vector4d calc_transform(const Eigen::Vector4d & p) const;
};


class DHModel
{
private:
    std::vector<DHChainElement> chain;

public:
    DHModel();
    DHModel(std::initializer_list<DHChainElement> init_list);
    Eigen::Vector4d calc_transform(const Eigen::Vector4d & p) const;
    DHChainElement & operator[](int i);
};

} // namespace dhmodel

#endif // DHMODEL