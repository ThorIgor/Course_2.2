#include "TComplex.h"
#include "AComplex.h"

ostream& operator<<(ostream& os, const TComplex& c)
{
    os << c.mod() << "*(cos" << c.arg() << "+isin" << c.arg() << ")";
    return os;
}

TComplex::TComplex(const double& r, const double& fi) : _r(r), _fi(fi)
{
}

TComplex::TComplex(const TComplex& that) : _r(that._r), _fi(that._fi)
{
}

TComplex::~TComplex()
{
}

TComplex::operator AComplex() const
{
    return AComplex(re(), im());
}

TComplex& TComplex::operator=(const TComplex& that)
{
    _r = that._r;
    _fi = that._fi;
    return *this;
}

const TComplex TComplex::operator+(const TComplex& that) const
{
    AComplex u(re() + that.re(), im() + that.im());
    return TComplex(u.mod(), u.arg());
}

const TComplex TComplex::operator-(const TComplex& that) const
{
    AComplex u(re() - that.re(), im() - that.im());
    return TComplex(u.mod(), u.arg());
}

const TComplex TComplex::operator*(const TComplex& that) const
{
    return TComplex(_r*that._r, _fi*that._fi);
}

const TComplex TComplex::operator/(const TComplex& that) const
{
    return TComplex(_r/that._r, _fi/that._fi);
}

bool TComplex::operator==(const TComplex& that) const
{
    return (_r == that._r) && (_fi == that._fi);
}

bool TComplex::operator!=(const TComplex& that) const
{
    return !(*this == that);
}
