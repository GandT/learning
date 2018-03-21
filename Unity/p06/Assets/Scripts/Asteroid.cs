using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Asteroid : MonoBehaviour {

	Rigidbody _rigidbody;
	Transform _transform;

	float tumble = 5;
	float speed = -5;

	void Start () {
		// アクセスするオブジェクトの取得
		_rigidbody = GetComponent<Rigidbody>();
		_transform = GetComponent<Transform>();

		// 角度設定
		_rigidbody.angularVelocity = Random.insideUnitSphere * tumble;

		// 速度設定
		_rigidbody.velocity = _transform.forward * speed;

	}
}
