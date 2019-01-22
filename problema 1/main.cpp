#include <iostream>
using namespace std;
struct nod
{
    int info;
    nod *prev,*next;
};
nod *prim, *ultim;
int nr;
int nrNoduri()
{
    int nr=0;
    nod *p=prim;
    while(p!=NULL)
    {
        p=p->next;
        nr++;
    }
    return nr;
}
int esteVida()
{
    return prim==NULL;
}
void creare_adaugare(int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        if(prim==NULL)
        {
            prim=new nod;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>prim->info;
            prim->next=0;
            prim->prev=0;
            ultim=prim;
        }
        else
        {
            nod *c;
            c=new nod;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>c->info;
            ultim->next=c;
            c->prev=ultim;
            ultim=c;
            ultim->next=0;
        }
    }
}
void adaugaFinal(int x)
{
    if(prim==NULL)
    {
        prim=new nod;
        prim->info=x;
        prim->next=0;
        prim->prev=0;
        ultim=prim;
    }
    else
    {
        nod *c;
        c=new nod;
        c->info=x;
        ultim->next=c;
        c->prev=ultim;
        ultim=c;
        ultim->next=0;
    }
}
void adaugaInceput(int x)
{
    nod *p,*q=ultim;
    if(prim==NULL)
    {
        prim=new nod;
        prim->info=x;
        prim->next=0;
        prim->prev=0;
        ultim=prim;
    }
    else
    {
        while(q)
            q=q->prev;
        p=new nod;
        p->info=x;
        p->next=prim;
        prim=p;
    }
}
void adaugaPePozitie(int k,int x)
{
    int i;
    nod *p,*q=prim;
    if(k<=1)
        adaugaInceput(x);
    else if(k>nrNoduri())
        adaugaFinal(x);
    else
    {
        for(i=1; i<=k-2; i++)
            q=q->next;
        p=new nod;
        p->info=x;

        p->prev=q->prev;
        p->next=q->next;
        q->next=p;
        q->prev=p;
    }
}
void afisare()
{
    nod *p=prim;
    if(prim==NULL)
        cout<<"Lista este goala";
    while(p)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
void afisare_inversa()
{
      nod *r, *urm, *ant;
    r=prim;
    ant=NULL;
    while(r!=NULL)
    {
        urm=r->next;
        r->next=ant;
        ant=r;
        r=urm;
    }
    prim=ant;
    afisare();
}
void stergereNod(int x)
{
    if(prim==NULL)
        return ;
    else
    {
        if (prim->info==x)
        {
            nod *aux=prim;
            prim=prim->next;
            delete aux;
        }
        else
        {
            nod *q=prim;
            while (q->next->info!=x)
                q=q->next;
            nod *aux=q->next;
            q->next=q->next->next;
            delete aux;
        }
    }
}
void stergerePozitie(int k)
{
    int i;
    nod *aux, *p;
    if(prim==NULL)
        return ;
    else
    {
        if(k==1)
        {
            aux=prim;
            prim=prim->next;
            delete aux;
        }
        else
        {
            p=prim;
            for(i=1; i<=k-2; i++)
                p=p->next;
            aux=p->next;
            p->next=aux->next;
            delete aux;
        }
    }
}
int main()
{
    int x, a, k;
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    afisare();
    do{
    cout<<endl<<"\t\tMeniu"<<endl<<endl;
    cout<<"Introduceti 1 pentru adaugarea unui element la inceputul listei: "<<endl;
    cout<<"Introduceti 2 pentru adaugarea unui element la sfarsitul listei: "<<endl;
    cout<<"Introduceti 3 pentru adaugarea unui element in interiorul listei: "<<endl;
    cout<<"Introduceti 4 pentru afisarea elementelor in ordinea introducerii lor: "<<endl;
    cout<<"Introduceti 5 pentru afisarea elementelor in ordine inversa: "<<endl;
    cout<<"Introduceti 6 pentru stergerea unui element de pe o pozitie stiuta: "<<endl;
    cout<<"Introduceti 7 pentru stergerea unui element cu o anumita valoare: "<<endl;
    cout<<"Optiunea aleasa este: ";
    cin>>x;
    switch(x)
    {
    case 1:
        cout<<"Introduceti valoarea pe care doriti sa o introduceti in lista: ";
        cin>>a;
        adaugaInceput(a);
        afisare();
        break;
    case 2:
        cout<<"Introduceti valoarea pe care doriti sa o introduceti in lista: ";
        cin>>a;
        adaugaFinal(a);
        afisare();
        break;
    case 3:
        cout<<"Introduceti valoarea pe care doriti sa o introduceti in lista: ";
        cin>>a;
        cout<<"Introduceti pozitia pe care doriti sa introduceti valoarea "<<a<<": ";
        cin>>k;
        adaugaPePozitie(k, a);
        afisare();
        break;
    case 4:
        afisare();
        break;
    case 5:
        afisare_inversa();
        break;
    case 6:
        afisare_inversa();
        cout<<endl<<"Introduceti pozitia elementului pe care doriti sa il stergeti din lista: ";
        cin>>a;
        stergerePozitie(a);
        afisare();
        break;
    case 7:
        afisare();
        cout<<endl<<"Introduceti elementul pe care doriti sa il stergeti din lista: ";
        cin>>a;
        stergereNod(a);
        afisare();
        break;
    default:
        cout<<"Optiunea aleasa este incorecta. Inchideti programul si incercati din nou.";
        break;
    }
    }while(x!=0 && x<=7);
    return 0;
}
