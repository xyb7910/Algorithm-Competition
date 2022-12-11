using Iter = list<int>::iterator;

const int maxN = 1e5 + 10;
Iter pos[maxN];
list<int> queList;
bool erased[maxN];
int N;

void buildQueue()
{
  queList.push_front(1);
  pos[1] = queList.begin();

  for (int i = 2; i <= N; i++)
  {
    int k, p;
    scanf("%d%d", &k, &p);
    if (p == 0)
    {
      pos[i] = queList.insert(pos[k], i); //left
    }
    else
    {
      auto nextIter = next(pos[k]);
      pos[i] = queList.insert(nextIter, i); //right
    }
  }
  int M;
  scanf("%d", &M);
  for (int x, i = 1; i <= M; i++)
  {
    scanf("%d", &x);
    if (!erased[x])
    {
      queList.erase(pos[x]);
    }
    erased[x] = true;
  }
}

int main()
{
  scanf("%d", &N);
  buildQueue();
  bool first = true;
  for (int x: queList)
  {
    if (!first)
      putchar(' ');
    first = false;
    printf("%d", x);
  }
  putchar('\n');
  return 0;
}
