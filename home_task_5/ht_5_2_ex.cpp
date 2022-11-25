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
    static void ChangetColor(Laptop&laptop,string color)
    {
        laptop.color = color;
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

    for(int i=0; i<n; i++)
    {
        cout << "Введите вес: ";
        cin >> Weight;
        cout << "Введите цвет ноутбука: ";
        cin >> Color;
        Laptop laptop(Weight, Color);
        _id_[i] = laptop.GetId();
        cout<<"Если цвет этого ноутбука вас устраивает, введите 1, если хотите перекрасить введите 0: ";
        cin >> change_or_not_change;
        if (change_or_not_change == 1)
        {
            _id_[i] = laptop.GetId();
            _weight_[i]=Weight;
            _color_[i]=Color;
            _change_or_not_change_[i]=1;
        }
        else
        {
            cout<<"Введите цвет, в который перекрасить: ";
            cin>>changed_color;
            Laptop::ChangetColor(laptop,changed_color);
            _id_[i] = laptop.GetId();
            _weight_[i]=Weight;
            _color_[i]=changed_color;
            _change_or_not_change_[i]=0;
        }

    }
    cout<<"Актуальные данные о компьютерах: \n ";
    for(int i=0; i<n; i++)
    {
    cout << "Компьютер весом "<< _weight_[i] << " грамм и"<<discribe_change_or_not_change(_change_or_not_change_[i]) << _color_[i] <<" цвет имеет id: "<< _id_[i] <<"\n ";
    }

}
