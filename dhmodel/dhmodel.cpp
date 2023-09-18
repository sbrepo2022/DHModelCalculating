#include "dhmodel.h"
#include <iostream>


namespace dhmodel
{

constexpr inline double deg_to_rad(double deg)
{
    return deg * M_PI / 180;
}

DHChainElement::DHChainElement(double theta, double a, double d, double alpha) : theta(theta), a(a), d(d), alpha(alpha)
{
}

void DHChainElement::set_theta(double theta)
{
    this->theta = theta;
}

Eigen::Vector4d DHChainElement::calc_transform(const Eigen::Vector4d & p) const
{
    Eigen::Matrix4d T;
    T << cos(deg_to_rad(theta)), -sin(deg_to_rad(theta)) * cos(deg_to_rad(alpha)),
      sin(deg_to_rad(theta)) * sin(deg_to_rad(alpha)), a * cos(deg_to_rad(theta)), sin(deg_to_rad(theta)),
      cos(deg_to_rad(theta)) * cos(deg_to_rad(alpha)), -cos(deg_to_rad(theta)) * sin(deg_to_rad(alpha)),
      a * sin(deg_to_rad(theta)), 0, sin(deg_to_rad(alpha)), cos(deg_to_rad(alpha)), d, 0, 0, 0, 1;

#ifdef DEBUG_MODE
    std::cout << "Calculated position:\n" << T * p << "\n\n--------\n\n";
#endif

    return T * p;
}

DHModel::DHModel()
{
}

DHModel::DHModel(std::initializer_list<DHChainElement> init_list)
{
    chain.reserve(init_list.size());
    for (const auto & elem : init_list)
    {
        chain.push_back(elem);
    }
}

Eigen::Vector4d DHModel::calc_transform(const Eigen::Vector4d & p) const
{
    Eigen::Vector4d result = p;
    for (const auto & chain_elem : chain)
    {
        result = chain_elem.calc_transform(result);
    }
    return result;
}

DHChainElement & DHModel::operator[](int i)
{
    return chain[i];
}

} // namespace dhmodel