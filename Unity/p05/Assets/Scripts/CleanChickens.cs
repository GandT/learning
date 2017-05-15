using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CleanChickens : MonoBehaviour {

	private void OnTriggerEnter(Collider other)
	{
		// あたり判定発生時に相手を削除
		GameObject.DestroyObject(other.gameObject);
	}
}
