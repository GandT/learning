using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameArea : MonoBehaviour{

	// 領域からオブジェクトが離れた際に呼び出される
	void OnTriggerExit(Collider other)
	{
        Destroy(other.gameObject);
    }
}
