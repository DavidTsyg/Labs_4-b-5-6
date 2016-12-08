#include <wchar.h>
#include <iostream>
using namespace std;
struct Firearm
{
	char model[64];
	unsigned int year;
	char country[32];
};

struct List
{
	Firearm firearm;
	List *pNext;
};


void addFirst(List *& pF, List* p)
{
	p->pNext = pF;
	pF = p;
}

List * delFirst(List *&pF)
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;

}

bool add(List *&pF, List * pZad, List *p)
{

	if (pZad == pF)
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF;
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false;
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}

List * del(List*& pF, List *p)
{
	if (pF == 0) return 0;
	if (pF == p)
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF;
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0;
		pPred->pNext = p->pNext;
		return p;
	}
    while (delFirst(pF));
}

int main(int argc, char* argv[])
{
    List *pF = 0;
    List *p;

    char Ex;
    do
    {
        p = (List *)malloc(sizeof(List));

        cout << endl;
        cout << "Model: ";
        cin.get();
        fflush(stdin);
        cin.getline(p->firearm.model, 63);

        cout << "Country: ";
        fflush(stdin);
        cin.getline(p->firearm.country, 31);

        cout << "Year: ";
        fflush(stdin);
        cin >> p->firearm.year;

        addFirst(pF, p);
        printf("Press 'y' or 'Y' to continue or press any other key to exit ");
        cin >> Ex;
        cin.clear();
        cout << endl;

    } while (Ex == 'Y' || Ex == 'y');
    cout << endl;

    for (List *pi = pF; pi; pi = pi->pNext)
        cout << pi->firearm.model << " " << pi->firearm.country << " " << pi->firearm.year << endl;

    for (List *pi = pF; pi->pNext;)
    {
        double min = pi->firearm.year;
        List *pmin = pi;
        for (List *pj = pi->pNext; pj; pj = pj->pNext)
            if (pj->firearm.year<min)
            {
                min = pj->firearm.year;
                pmin = pj;
            }
        if (pi != pmin)
        {
            del(pF, pmin);
            add(pF, pi, pmin);
        }
        else pi = pi->pNext;
    }

    cout << endl;
    cout << "Sorted: " << endl;
    for (List *pi = pF; pi; pi = pi->pNext)
        cout << pi->firearm.model << " " << pi->firearm.country << " " << pi->firearm.year << endl;
    return 0;
}
