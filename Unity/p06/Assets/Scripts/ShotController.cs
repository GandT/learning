using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShotController : MonoBehaviour{

	Rigidbody _rigidbody;
	Transform _transform;

	float speed = 20;

	void Start () {
		// アクセスするオブジェクトの取得
		_rigidbody = GetComponent<Rigidbody>();
		_transform = GetComponent<Transform>();

		// パラメータ設定
		_rigidbody.velocity = _transform.forward * speed;
	}


	void Update () {
		
	}
}
