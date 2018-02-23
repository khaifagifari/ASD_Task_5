#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */
    if (first(L) != NULL)
    {
        address Q = first(L);
        do {
            cout<<"name    : "<<info(Q).name<<endl
                <<"ID      : "<<info(Q).ID<<endl
                <<"location: "<<info(Q).location<<endl;
            Q = next(Q);
        } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}
    else
    {
        cout<<"EMPTY!"<<endl;
    }
}

void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L, int ndata) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------
    int n = ndata / 2;
    address P, Q = new elmlist;
    if (first(L) != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            n = randomInt(15);
            Q = first(L);
            for (int j = 0; j<n; j++)
            {
                Q = next(Q);
            }
            deleteAfter(L, Q, P);
            insertLast(L, P);
            n = randomInt(20);
            for (int j = 0; j<n; j++)
            {
                Q = next(Q);
            }
            if (first(L) != Q)
            {
                deleteFirst(L, P);
            }
            else
            {
                deleteLast(L, P);
            }
            insertAfter(L, Q, P);
        }
    }
    else
    {
        cout<<"List musik anda kosong."<<endl;
    }
    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------
    List K;
    createList(K);
    bool ketemu = false;
    address P = new elmlist;
    address Q = new elmlist;
    while (first(L) != NULL)
    {
        deleteFirst(L, P);
        if (first(K) != NULL)
        {
            if (info(P).ID < info(first(K)).ID)
            {
                insertFirst(K, P);
            }
            else if (info(P).ID > info(last(K)).ID)
            {
                insertLast(K, P);
            }
            else
            {
                Q = first(K);
                do
                {
                    if (info(P).ID < info(next(Q)).ID)
                    {
                        insertAfter(K, Q, P);
                        ketemu = true;
                    }
                    Q = next(Q);
                }
                while (Q != first(K) && !ketemu);
            }
        }
        else
        {
            insertFirst(K, P);
        }
    }
    L = K;
    //----------------------------------------

}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------
    for (int i = 0; i < n; i++)
    {
        address P = new elmlist;
        P = first(L);
        do
        {
            playMusic(P);
            P = next(P);
        }
        while (P!=first(L));
    }
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------
    if (first(L) != NULL)
    {
        address Q = new elmlist;
        Q = findElmByID(L, x);
        if (Q!=NULL)
        {
            address P = new elmlist;
            address R = new elmlist;
            R = prev(Q);
            deleteAfter(L, R, P);
            deallocate(P);
        }
    }
    else
    {
        cout<<"list musik anda kosong"<<endl;
    }
    //----------------------------------------

}
