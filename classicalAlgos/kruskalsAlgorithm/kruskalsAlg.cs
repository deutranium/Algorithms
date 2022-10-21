static void
Main (string[]args)
{
  int k = 1;
  int vert = 4;
  int e = 0;
  KGraph objGraph = new KGraph (vert);	//Step 1
  KVertex[]vertcoll = objGraph.vertcoll;
  KEdge[]result = new KEdge[vert];

  List < KEdge > edgecoll = new List < KEdge > ();	//Step 2
  KEdge objEdge = new KEdge ();

  for (int i = 0; i < vert; i++)	//Step 3
    {
      for (int j = i; j < vert; j++)
	{
	  if (i != j)
	    {
	      Console.WriteLine ("KEdge weight from src{0} to destn{1}", i,
				 j);
	      int wt = int.Parse (Console.ReadLine ());
	      if (wt == 0)
		continue;
	      objEdge = new KEdge (vertcoll[i], vertcoll[j], wt);
	      edgecoll.Add (objEdge);
	      k++;
	    }
	}
    }

  objGraph.Edgecoll = edgecoll.ToList ().OrderBy (p = >p.weight).ToList ();

  KSubsets[]sub = new KSubsets[vert];	//Step 4
  KSubsets subobj;
  for (int i = 0; i < vert; i++)
    {
      subobj = new KSubsets ();
      subobj.parent = vertcoll[i];
      subobj.rank = 0;
      sub[i] = subobj;
    }
  k = 0;
  while (e < vert - 1)
    {
      objEdge = objGraph.Edgecoll.ElementAt (k);
      KVertex x = find (sub, objEdge.V1, Array.IndexOf (objGraph.vertcoll, objEdge.V1), objGraph.vertcoll);	//Step 5
      KVertex y = find (sub, objEdge.V2, Array.IndexOf (objGraph.vertcoll, objEdge.V2), objGraph.vertcoll);	//Step 6
      if (x != y)
	{
	  result[e] = objEdge;
	  Union (sub, x, y, objGraph.vertcoll);
	  e++;
	}
      k++;
    }

  for (int i = 0; i < e; i++)	//Step 7
    {
      Console.WriteLine ("edge from src:{0} to dest:{1} with weight:{2}",
			 result[i].V1.Label, result[i].V2.Label,
			 result[i].weight);
    }
  return;
}
