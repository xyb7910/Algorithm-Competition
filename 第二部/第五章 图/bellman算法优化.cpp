bool bellman_ford(int x)
{
  int i,j,k;
  bool relaxed;//����Ƿ�������ɳڲ��� 
  for(i=1;i<=n;i++)//��ʼ�� 
    d[i]=INT_MAX;
  d[x]=0;
  for(i=1;i<n;i++)
  {
    relaxed=0;//Ĭ��δ�����ɳ۲���
    for(j=1;j<=n;j++)
      for(k=1;k<=n;k++)
        if(w[j][k]!=INT_MAX && d[k]!=INT_MAX && d[j]>d[k]+w[j][k])
        {
          d[j]=d[k]+w[j][k];
          relaxed=1;//�������ɳڲ��� 
        }
    if(!relaxed)//��δ�����ɳڲ���������ѭ�� 
    ��break;
  }
  for(i=1;i<=n;i++)//��֤�Ƿ��и���
    for(j=1;j<=n;j++)
      if(w[j][k]!=INT_MAX && d[k]!=INT_MAX && d[j]>d[k]+w[j][k])
        return 1;//�и��� 
  return 0;//�޸���      
}
