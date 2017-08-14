class BigInt
{
public:
    vector<short> v;
    BigInt()
    {
        v.pb(0);
    }

    void output()
    {
        for(int i = v.size()-1; i >= 0; i--)
        {
            cout << v[i];
        }
    }

    BigInt operator+ (BigInt const &a)
    {
        short carry = 0;
        int mx = max(a.v.size(), this->v.size());
        vector<short> tmp(mx);
        for(int i = 0; i < mx || carry; i++)
        {
            if(i > mx-1) tmp.pb(0);
            tmp[i] = (i > a.v.size()-1 ? 0: a.v[i]) + (i > this->v.size()-1 ? 0 : this->v[i]) + carry;
            carry = (int)(tmp[i] >= 10);
            if(carry) tmp[i] -= 10;
        }
        BigInt ans;
        ans.v = tmp;
        return ans;
    }
};
