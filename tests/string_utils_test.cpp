#include "string_utils.h"
#include <assert.h>
#include <iostream>

using namespace std::string_literals;

int main() {
    auto ut{ utils::to_upper("not uppercAse"s) };
    auto lt{ utils::to_lower("NoT loWerCasE"s) };
    auto rt{ utils::reverse("abc"s) };

    auto btt{ utils::trim("   trimmed   "s) };
    auto ltt{ utils::trim_left("   trimmed   "s) };
    auto rtt{ utils::trim_right("   trimmed   "s) };

    auto srt{ utils::remove("remove *s"s, '*') };
    auto rrt{ utils::remove("remove rs"s, 's') };
    
    auto sst{ utils::split("split this by space"s, ' ') };
    auto ust{ utils::split("split_this_by underscore_(_)"s, '_') };

    assert(ut == "NOT UPPERCASE"s);
    assert(lt == "not lowercase"s);
    assert(rt == "cba"s);
    assert(btt == "trimmed"s);
    assert(ltt == "trimmed   "s);
    assert(rtt == "   trimmed"s);
    assert(srt == "remove s"s);
    assert(rrt == "remove r"s);
    
    auto sst_v = std::vector<std::string>{"split"s, "this"s, "by"s, "space"s};
    assert(sst == sst_v);
    
    auto ust_v = std::vector<std::string>{"split"s, "this"s, "by underscore"s, "("s, ")"s};
    assert(ust == ust_v);
}