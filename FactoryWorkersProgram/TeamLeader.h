#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include <string>
#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker
{
private:
    float monthlyBonus;

    int requiredHours;
    int attendedHours;

public:
    TeamLeader(std::string name, int num, int m, int d, int y, int shift, float wage, float bonus, int reqHrs, int attHrs);

    inline float getBonus() const
    {
        return monthlyBonus;
    }
    inline int getReqHrs() const
    {
        return requiredHours;
    }
    inline int getAttHrs() const
    {
        return attendedHours;
    }

    void setBonus(float newBonus);
    void setReqHrs(int newHours);
    void setAttHrs(int newHours);

    void printTeamLeader() const;
};
#endif // TEAMLEADER_H
