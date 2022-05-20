#include "AComplex.h"
#include "TComplex.h"

ostream& operator<<(ostream& os, const AComplex& c)
{
    os << c.re() << "+" << c.im() << "i";
    return os;
}

AComplex::AComplex(const double& re, const double& im) : _re(re), _im(im)
{
}

AComplex::AComplex(const AComplex& that) : _re(that._re), _im(that._im)
{
}

AComplex::~AComplex()
{
}

AComplex::operator TComplex() const
{
    return TComplex(mod(), arg());
}

AComplex& AComplex::operator=(const AComplex& that)
{
    _re = that._re;
    _im = that._im;
    return *this;
}

const AComplex AComplex::operator+(const AComplex& that) const
{
    return AComplex(_re+that._re, _im+that._im);
}

const AComplex AComplex::operator-(const AComplex& that) const
{
    return AComplex(_re - that._re, _im - that._im);
}

const AComplex AComplex::operator*(const AComplex& that) const
{
    TComplex u(mod() * that.mod(), arg() + that.arg());
    return AComplex(u.re(), u.im());
}

const AComplex AComplex::operator/(const AComplex& that) const
{
    TComplex u(mod() / that.mod(), arg() - that.arg());
    return AComplex(u.re(), u.im());
}

bool AComplex::operator==(const AComplex& that) const
{
    return (_re == that._re) && (_im == that._im);
}

bool AComplex::operator!=(const AComplex& that) const
{
    return !(*this == that);
}
