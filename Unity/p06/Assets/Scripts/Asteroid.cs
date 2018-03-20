using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Asteroid : MonoBehaviour {

	Rigidbody _rigidbody;

	float tumble = 5;

	void Start () {
		// アクセスするオブジェクトの取得
		_rigidbody = GetComponent<Rigidbody>();

		// 角度設定
		_rigidbody.angularVelocity = Random.insideUnitSphere * tumble;

	}
}
