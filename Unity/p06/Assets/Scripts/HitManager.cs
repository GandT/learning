using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HitManager : MonoBehaviour {

	//接触時処理
	void OnTriggerEnter(Collider other)
	{
		// システム用オブジェクトは無視する
		if(other.tag == "GameController") return;

		// 相手を破壊
		Destroy(other.gameObject);
		// 自分を破壊
		Destroy(gameObject);
	}
}
