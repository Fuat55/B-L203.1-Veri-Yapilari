/*
20061108-Fuat ŞENGÜL
Ödev-5:İkili Ağaçlar
*/

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

typedef struct Node
{
    int plaka;
    struct Node *left;
    struct Node *right;
    struct Node *next;

} node;

//1. Binary (ikili) Ağaç Veri Yapısı ==> Başlangıç
node *root2 = NULL;
node *front = NULL, *rear = NULL;

node *yeni_node(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->plaka = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
node *ekle_sagdan(node *roott, int data)
{
    if (roott != NULL)
    {
        if (roott->right != NULL)
        {
            node *temp = roott->right;
            node *yeni = yeni_node(data);
            roott->right = yeni;
            yeni->right = temp;
            roott = yeni;
        }
        else
        {
            roott->right = ekle_sagdan(roott->right, data);
        }
    }
    else
        roott = yeni_node(data);
    return roott;
}
node *ekle_soldan(node *roott, int data)
{
    if (roott != NULL)
    {
        if (roott->left != NULL)
        {
            node *temp = roott->left;
            node *yeni = yeni_node(data);
            roott->left = yeni;
            yeni->left = temp;
            roott = yeni;
        }
        else
        {
            roott->left = ekle_soldan(roott->left, data);
        }
    }
    else
        roott = yeni_node(data);

    return roott;
}
void preorder(node *roott)
{
    if (roott != NULL)
    {
        printf("%3d \n", roott->plaka);
        preorder(roott->left);
        preorder(roott->right);
    }
}
void inorder(node *roott)
{
    if (roott != NULL)
    {
        inorder(roott->left);
        printf("%3d \n", roott->plaka);
        inorder(roott->right);
    }
}
void postorder(node *roott)
{
    if (roott != NULL)
    {
        postorder(roott->left);
        postorder(roott->right);
        printf("%d \n", roott->plaka);
    }
}
void ekle(node *a)
{
    node *yeni = (node *)malloc(sizeof(node));
    yeni->plaka = a->plaka;
    yeni->next = NULL;
    if (front == NULL)
        front = rear = yeni;
    else
    {
        rear->next = yeni;
        rear = yeni;
    } 
}
node *cikar()
{
    if(front == NULL)
        printf("\nQueue is Empty!!!\n");
    else
    {
        node *temp = front;
        front = front->next;
        
        return temp;
    }
} 
//BFS Kısmında eksiklik var !!!
void bfs(node *a)
{
    printf("%d\n", a->plaka);
    if (a->left != NULL)
    {
        ekle(a->left);
    }
    if (a->right != NULL)
    {
        ekle(a->right);
    } 
    if (front != NULL)
    {
        node *t = cikar();
        bfs(t);
    }
}
  
//1. Binary (ikili) Ağaç Veri Yapısı ==> Bitiş

//2. Index Tablosu ==> Başlangıç
#define N 15
int OgrListe[N][2] = {{18060311, 40}, {20060045, 50}, {19061091, 75}, {20060134, 90}, {20060678, 40}, {18061086, 75}, {20060032, 50}, {20060067, 60}, {19060456, 60}, {18060245, 75}, {20060110, 40}, {20060234, 90}, {20060141, 60}, {20060011, 50}, {20060012, 60}};
typedef struct Indis
{
    int indisId;
    struct Indis *left;
    struct Indis *right;
} indis;
indis *root = NULL;
void testSiralama(indis *root)
{
    if (root != NULL)
    {
        testSiralama(root->left);
        printf("%d -", root->indisId);
        testSiralama(root->right);
    }
}
indis *yeniIndisNode(int ind)
{
    indis *yeni = (indis *)malloc(sizeof(indis));
    yeni->indisId = ind;
    yeni->left = NULL;
    yeni->right = NULL;
    return yeni;
}
indis *ekleIndis(indis *root, int ind)
{
    if (root != NULL)
    {
        if (OgrListe[ind][1] > OgrListe[root->indisId][1])
            root->right = ekleIndis(root->right, ind);
        else if (OgrListe[ind][1] < OgrListe[root->indisId][1])
            root->left = ekleIndis(root->left, ind);
        else
        {
            if (OgrListe[ind][0] > OgrListe[root->indisId][0])
                root->left = ekleIndis(root->left, ind);
            else
                root->right = ekleIndis(root->right, ind);
        }
    }
    else
        root = yeniIndisNode(ind);
    return root;
}
void degistir(int ogrenciNo, int guncelPuan)
{
    root = NULL;
    for (size_t i = 0; i < N; i++)
    {
        if (OgrListe[i][0] == ogrenciNo)
        {
            OgrListe[i][1] = guncelPuan;
            break;
        }
    }

    root = ekleIndis(root, 0);
    for (size_t i = 1; i < N; i++)
    {
        ekleIndis(root, i);
    }
}
void yazdir(indis *root, int puan)
{
    if (root != NULL)
    {
        yazdir(root->left, puan);

        if (puan < OgrListe[root->indisId][1])
        {
            printf("%d - %d\n", OgrListe[root->indisId][0], OgrListe[root->indisId][1]);
        }

        yazdir(root->right, puan);
    }
}
indis *silIndis(indis *root, int ind)
{
    indis *p, *q;
    if (root == NULL)
        return NULL;
    if (OgrListe[root->indisId][1] == OgrListe[ind][1])
    {
        if (OgrListe[ind][0] == OgrListe[root->indisId][0])
            if (root->left == root->right)
            {
                free(root);
                return NULL;
            }
            else
            {
                if (root->left == NULL)
                {
                    p = root->right;
                    free(root);
                    return p;
                }
                else if (root->right == NULL)
                {
                    p = root->left;
                    free(root);
                    return p;
                }
                else
                {
                    p = q = root->right;
                    while (p->left != NULL)
                        p = p->left;
                    p->left = root->left;
                    free(root);
                    return q;
                }
            }
        else if (OgrListe[ind][0] > OgrListe[root->indisId][0])
            root->left = silIndis(root->left, ind);
        else
            root->right = silIndis(root->right, ind);
    }
    else if (OgrListe[root->indisId][1] < OgrListe[ind][1])
        root->right = silIndis(root->right, ind);
    else
        root->left = silIndis(root->left, ind);
    return root;
}
//2. Index Tablosu ==> Bitiş

int main()
{
    //1. Binary (ikili) Ağaç Veri Yapısı ==>Başlangıç==>Test

    /*root2 = ekle_sagdan(root2, 5);
    ekle_soldan(root2, 10);
    ekle_soldan(root2, 6);
    ekle_sagdan(root2, 7);
    preorder(root2);
    printf("\n");
    inorder(root2);
    printf("\n");
    postorder(root2);
    printf("\n");
    bfs(root2);*/
    //1. Binary (ikili) Ağaç Veri Yapısı ==> Bitiş

    //3, 11, 9, 5, 2, 8, 14, 7, 12, 13, 6, 1, 0, 10, 4
    //2. Index Tablosu ==> Başlangıç==>Test
    //root = ekleIndis(root, 0);
    /*for (size_t i = 1; i < N; i++)
    {
        ekleIndis(root, i);
    }*/
    //degistir(20060011,100);
    //yazdir(root, 75);
    //testSiralama(root);
    //silIndis(root,13);
    //2. Index Tablosu ==> Bitiş==>Test

    return 0;
}
