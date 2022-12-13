#include <iostream>

using namespace std;

class Laptop{
public:

    Laptop(int weight, string color)
    {
        this->weight = weight;
        this->color = color;
        Count++;
        id = Count;
    }

    int GetId()
    {
        return id;
    }
    int GetWeight()
    {
        return weight;
    }
    string GetColor()
    {
        return color;
    }
    void SetColor(std::string color)
    {
        color=color;
    }
    void SetWeight(int weight)
    {
        weight=weight;
    }


    Laptop operator = (Laptop & laptopI)
    {
        color = laptopI.color;
        weight = laptopI.weight;
        return Laptop(weight,color);
    }

private:
    static int Count;
    int weight;
    string color;
    int id;

};
int Laptop::Count=0;

std::string discribe_change_or_not_change(int change_color_or_not)
{
    if (change_color_or_not == 1) return " цветом ";
    else return " был перекрашен в ";
}

int main()
{   int n;
    int Weight;
    string Color;
    cout <<"Введите колличество компьютеров: ";
    cin >> n;
    int _id_[n];
    int _weight_[n];
    string _color_[n];
    int change_or_not_change;
    string changed_color;
    int _change_or_not_change_[n];
    Laptop laptop(Weight, Color);
    Laptop laptopI(laptop.GetWeight(),changed_color);

    for(int i=0; i<n; i++)
    {
        cout << "Введите вес: ";
        cin >> Weight;
        laptop.SetWeight(Weight);
        cout << "Введите цвет ноутбука: ";
        cin >> Color;
        laptop.SetColor(Color);
        Laptop laptop(Weight, Color);
        _id_[i] = laptop.GetId();
        cout<<"Если цвет этого ноутбука вас устраивает, введите 1, если хотите перекрасить введите 0: ";
        cin >> change_or_not_change;
        if (change_or_not_change == 1)
        {
            laptop=laptop;
            _change_or_not_change_[i]=1;
            cout << "Компьютер весом "<< laptop.GetWeight() << " грамм и " << laptop.GetColor() <<" цветa имеет id: "<< laptop.GetId() <<"\n ";
        }

        else
        {
            cout<<"Введите цвет, в который перекрасить: ";
            cin>>changed_color;
            laptop=laptopI;
            _change_or_not_change_[i]=0;
            cout<< "Цвет изменился на новый: " << laptop.GetColor();
            cout << "Компьютер весом "<< laptop.GetWeight() << " грамм и " << " был перекрашен в "<< laptop.GetColor() <<" цвет с новым id: "<< laptop.GetId() <<"\n ";
        }
        }

}