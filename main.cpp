#include <iostream>

struct AdInsights {
    int adsWatched {};
    double percentageClicked {};
    double avgEarnings {};
};

void getAdInsights(AdInsights ai){
    std::cout << ai.adsWatched << " ads were watched today.\n";
    std::cout << ai.percentageClicked * 100 << " % of users clicked on an ad.\n";
    std::cout << "Your average earnings per ad stand at: " << ai.avgEarnings << " E.\n";

    double earnings = ai.adsWatched * ai.percentageClicked * ai.avgEarnings;
    std::cout << "You earned " << earnings << " euros today.\n";

}

int main()
{
    AdInsights today {500, 0.25, 0.05};
    getAdInsights(today);
    return 0;
}