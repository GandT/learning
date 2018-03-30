using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[System.Serializable] class Boundary
{
	public float xMin = 0, xMax = 0, zMin = 0, zMax = 0;
}


public class PlayerController : MonoBehaviour {

	Rigidbody _rigidbody;
	AudioSource _audio;

	float speed = 10;
	float tilt = 4;
	[SerializeField] Boundary boundary = null;

	float time = 0, shotTime = 0, nextTime = 0.2f;

	[SerializeField] GameObject shot = null;
	[SerializeField] Transform spawn = null;

	void Start()
	{
		// 変数の初期化
		_rigidbody = GetComponent<Rigidbody>();
		_audio = GetComponent<AudioSource>();
	}

	
	void Update()
	{
		// 時間カウント
		time += Time.deltaTime;

		// 自機弾発射
		if (Input.GetButton("Fire1") && time > shotTime) {
            shotTime = time + nextTime;
            Instantiate(shot, spawn.position, spawn.rotation);

			// 効果音
			_audio.Play();
        }
		
	}


	// 物理演算処理後に呼び出されるUpdate
	void FixedUpdate () {
		// 移動
		float moveHorizontal = Input.GetAxis("Horizontal");
		float moveVertical   = Input.GetAxis(  "Vertical");
		_rigidbody.velocity = new Vector3(moveHorizontal * speed, 0, moveVertical * speed);

		// 領域制限
		_rigidbody.position = new Vector3(
			Mathf.Clamp(_rigidbody.position.x, boundary.xMin, boundary.xMax),
			0,
			Mathf.Clamp(_rigidbody.position.z, boundary.zMin, boundary.zMax)
		);

		// 機体の傾き
		_rigidbody.rotation = Quaternion.Euler(0, 0, _rigidbody.velocity.x * -tilt);
	}
}
