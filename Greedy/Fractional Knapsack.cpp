//MAIN LOGIC

struct Items{
    int value;
    int weight;
    double ratio;
};

bool comparator(Items it1, Items it2)
{
    return(it1.ratio>it2.ratio);
}

double fractionalKnapsack(int W, Item arr[], int n)
{
   Items it[n];
   
   for(int i=0; i<n; i++)
   {
       it[i].value=arr[i].value;
       it[i].weight=arr[i].weight;
       it[i].ratio =((double)arr[i].value/arr[i].weight);
   }
   
   sort(it, it+n, comparator);
   
   double maxProfit=0;
   int i=0;
   while(i<n && W!=0)
   {
       if(it[i].weight<=W)
       {
           maxProfit+=it[i].value;
           W-=it[i].weight;
       }
       else
       {
           maxProfit+=((double)W*it[i].ratio);
           break;
       }
       i++;
   }
   return maxProfit;
   
    
}

