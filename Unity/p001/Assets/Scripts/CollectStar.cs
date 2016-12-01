using UnityEngine;
using System.Collections;

public class CollectStar : MonoBehaviour {

	void OnTriggerEnter (Collider c)
	{
		if(c.GetComponent<Rotator>())
		{
			Destroy(c.gameObject);
			Debug.Log("get star!");
		}
	}
}