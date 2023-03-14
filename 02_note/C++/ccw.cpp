ll ccw(pair<ll, ll> c, pair<ll, ll> b, pair<ll, ll> a)
{
    pair<ll, ll> m[2];
    m[0] = {b.first - a.first, b.second - a.second};
    m[1] = {b.first - c.first, b.second - c.second};
    return m[0].first * m[1].second - m[0].second * m[1].first;
}
