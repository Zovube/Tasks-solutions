#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point_t {
    ll x, y;

    point_t() = default;
    point_t(ll x, ll y) : x(x), y(y) {}

    point_t operator - (const point_t &p) const {
        return { x - p.x, y - p.y };
    }

    ll length() const {
        return x * x + y * y;
    }

    static ll cross(const point_t &p1, const point_t &p2) {
        return p1.x * p2.y - p1.y * p2.x;
    }

    static ll distance(const point_t &p1, const point_t &p2) {
        return (p2 - p1).length();
    }
};

vector<point_t> convex_hull(const vector<point_t> & v) {
    if (v.size() < 2) return { v };

    vector<point_t> s = v;
    point_t base = *min_element(begin(s), end(s), [] (const point_t & a, const point_t & b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    sort(begin(s), end(s), [&] (const point_t & a, const point_t & b) {
        if (point_t::cross(a - base, b - base) == 0)
            return point_t::distance(base, a) < point_t::distance(base, b);
        return point_t::cross(a - base, b - base) > 0;
    });

    vector<point_t> c; ll n;
    for (size_t i = 0; i < s.size(); i++) {
        while ((n = c.size()) >= 2 && point_t::cross(c[n-1] - c[n-2], s[i] - c[n-1]) <= 0)
            c.pop_back();
        c.push_back(s[i]);
    }
    return c;
}

int main() {
    int n; cin >> n;
    vector<point_t> points;
    for (int i = 0; i < n; i++) {
        point_t point; cin >> point.x >> point.y;
        points.push_back(point);
    }

    int m; cin >> m;
    vector<point_t> query;
    for (int i = 0; i < m; i++) {
        point_t point; cin >> point.x >> point.y;
        query.push_back(point);
    }

    auto hull = convex_hull(points);

    int left_most_id = (int) (min_element(hull.begin(), hull.end(), [] (const point_t &p1, const point_t &p2) {
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    }) - hull.begin());
    int right_most_id = (int) (min_element(hull.begin(), hull.end(), [] (const point_t &p1, const point_t &p2) {
        return p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y);
    }) - hull.begin());
    int down_most_id = (int) (min_element(hull.begin(), hull.end(), [] (const point_t &p1, const point_t &p2) {
        return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
    }) - hull.begin());
    int upper_most_id = (int) (min_element(hull.begin(), hull.end(), [] (const point_t &p1, const point_t &p2) {
        return p1.y > p2.y || (p1.y == p2.y && p1.x > p2.x);
    }) - hull.begin());

    auto took_points_from_to = [] (int from, int to, const vector<point_t> &v) {
        vector<int> result;

        int i = from;
        do {
            result.push_back(i);
            i = (i + 1) % (int) v.size();
        } while (i != to);

        return result;
    };

    vector<int> chains[4];
    chains[0] = took_points_from_to(right_most_id, upper_most_id, hull);
    chains[1] = took_points_from_to(upper_most_id, left_most_id, hull);
    chains[2] = took_points_from_to(left_most_id, down_most_id, hull);
    chains[3] = took_points_from_to(down_most_id, right_most_id, hull);

    auto is_chain_visible = [&] (const point_t &eye, const vector<int> &chain) {
        assert(chain.size() > 1);
        point_t p1 = hull[chain[0]];
        point_t p2 = hull[chain[1]];
        return point_t::cross(p1 - eye, p2 - eye) > 0;
    };

    auto find_corner_case_left = [] (const point_t &eye, const vector<int> &chain) {
        int l = 0, r = (int) chain.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            int mn = (chain[m] + 1) % (int) hull.size();
            point_t p1 = hull[chain[m]];
            point_t p2 = hull[mn];
            if (point_t::cross(p1 - eye, p2 - eye) > 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return chain[l];
    };

    auto find_corner_case_right = [] (const point_t &eye, const vector<int> &chain) {
        int l = 0, r = (int) chain.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            int mn = (chain[m] + 1) % (int) hull.size();
            point_t p1 = hull[chain[m]];
            point_t p2 = hull[mn];
            if (point_t::cross(p1 - eye, p2 - eye) > 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return chain[l];
    };

    for (int i = 0; i < m; i++) {
        point_t point = query[i];
        vector<int> corner_cases;
        for (int j = 0; j < 4; j++) {
            if (is_chain_visible(point, chains[j])) {
                corner_cases.push_back(find_corner_case_left(point, chains[j]));
            }
        }
    }

    return 0;
}