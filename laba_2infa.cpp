/*
Вариант 22. Два сплава
Имеется два сплава из двух металлов, соотношение этих металлов
в каждом из сплавов известно. Программа должна определять, какое
количество объёмных единиц первого и второго сплава нужно взять,
чтобы получить третий сплав с заданным соотношением этих
металлов.
Входные данные. Соотношение двух металлов в первом сплаве,
во втором сплаве и в требуемом сплаве, а также количество объёмных
единиц третьего сплава, которое требуется получить.
Выходные данные. Количество объёмных единиц первого и
второго сплава, которые следует соединить, для получения заданного
количества третьего сплава, либо сообщение о том, что получить
третий сплав из имеющихся двух невозможно.
*/

#include <iostream>
#include <iomanip>

using namespace std;

char contin() //зацикливание программы 
{
    char yesornot;
    cin >> yesornot;
    while (cin.peek() != '\n' || yesornot != 'Y' && yesornot != 'y' && yesornot != 'n' && yesornot != 'N')
    {
        cin.clear();
        cin.ignore(4321, '\n');
        cout << "Ошибка! введите корректные значения: <Y/N>";
        cin >> yesornot;
    }
    return yesornot;
}

double check()
{
    double chislo;
    while (!(cin >> chislo) || cin.peek() != '\n' || chislo < 0)
    {
        cin.clear();
        cin.ignore(1234, '\n');
        cout << "Ошибка! введите коррректное число :" << '\n';
    }
    return chislo;
}

double drob(double& num ,int& znamenatel) // функция превращения десятичной дроби в обычную 
{
    int n = 100; // максимальное количство иттераций
    int i = 2; 
    if (num == (int)num)
    {
        znamenatel = 1;
        return num, znamenatel = 1;
    }
    else
    { 
        while (num != ceil(num)) 
        {
            num = num * 10;
            znamenatel *= 10;
        }
        // упрощение дроби 
        while (i < n) // при сложных данных могут быть перебои
        {
            if ((int)num % i == 0 && (int)znamenatel % i == 0)
            {
                num = num / i;
                znamenatel = znamenatel / i;
                i = 2;
            }
            else i++;
        }
        return num,znamenatel;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    double sp1_1met, sp1_2met, sp2_1met, sp2_2met; 
    double splav1, splav2, splav3;
    double massa3;
    int n1, n2;

    double splav_1_do, splav_2_do, splav_3_do;

    int ch1, zn1 = 1;
    int ch2, zn2 = 1;
    int ch3, zn3 = 1;

    char yes_no;

    do 
    {
        cout << "Соотношение двух металлов в первом сплаве: ";
        splav1 = check();
        cout << "Соотношение двух металлов во втором сплаве: ";
        splav2 = check();
        cout << "Соотношение двух металлов в третьем сплаве: ";
        splav3 = check();
        cout << "количество объёмных единиц третьего сплава(будущего сплава) : ";
        massa3 = check();

        splav_1_do = splav1;
        splav_2_do = splav2;
        splav_3_do = splav3;

        drob(splav1, zn1);
        drob(splav2, zn2);
        drob(splav3, zn3);

        ch1 = splav1;
        ch2 = splav2;
        ch3 = splav3;

        if (splav_1_do > 1)
            n1 = ch1 + 1;
        else n1 = zn1 + 1;

        if (splav_2_do > 1)
            n2 = ch2 + 1;
        else n2 = zn2 + 1;

        sp1_1met = (double)ch1 / n1;
        sp1_2met = (double)zn1 / n1;
        sp2_1met = (double)ch2 / n2;
        sp2_2met = (double)zn2 / n2;

        bool flag = true;
        double min = INT_MAX;
        
        cout << "int max " << min<< endl;

        for (int x = 1; x < 100 && flag; x++) {
            for (int y = 1; y < 100 && flag; y++) {

                double m  = (abs(((sp1_1met * x + sp1_2met * y) * zn3) - ((sp2_1met * x + sp2_2met * y) * ch3)));
                if (m < min) min = m;
                if (abs(((sp1_1met * x + sp1_2met * y) * zn3 ) - ( (sp2_1met * x + sp2_2met * y) * ch3)) < 0.001) {
                    cout << "Масса первого сплава равна: " << ((double)massa3 / (x + y)) * x << '\n';
                    cout << "Масса второго сплава равна: " << ((double)massa3 / (x + y)) * y << '\n';
                    cout << endl;
                    flag = false;
                }
            }
        }

        cout << "m " << min << endl;

        if (flag == true)  cout << "получить третий сплав из имеющихся двух невозможно" << endl;

        cout << "соотношение первого металла в 1 сплаве" << sp1_1met << endl;
        cout << "соотношение второго металла в 1 сплаве" << sp1_2met << endl;
        cout << "соотношение первого металла в 2 сплаве" << sp2_1met << endl;
        cout << "соотношение второго металла в 2 сплаве" << sp2_2met << endl;

        cout << "Продолжить выполнение прогаммы ? <Y/N> ";
        yes_no = contin();
    } while (yes_no == 'Y' || yes_no == 'y');
    return 0;
}
