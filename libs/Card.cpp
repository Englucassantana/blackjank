
#include "Card.hpp"

string Card::getValue()
{
    return to_string(this->value);
}

int Card::getIntValue()
{
    return this->value;
}

void Card::setValue(string value)
{
    if (value == "J") this->value = 10;
    else if (value == "Q") this->value = 10;
        else if (value == "K") this->value = 10;
            else if (value == "Às") this->value = 1;
                else this->value = stoi(value);

}

string Card::getSuit()
{
    return this->suit;
}

void Card::setSuit(string suit)
{
    this->suit = suit;
}
