using UnityEngine;
using System.Collections;

public class Rotator : MonoBehaviour {

	// Y軸を毎フレーム Time.deltaTime * 100度回転させる
	void Update() {
		transform.Rotate(new Vector3(0, Time.deltaTime * 100, 0));
	}
}