using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shot : MonoBehaviour {

	// 外部設定する変数
	public GameObject prefab;
	public float power;

	// Use this for initialization
	void Start () {
		
	}
	
	void Update () {
		// マウスクリック時
		if (Input.GetMouseButtonDown(0)){ 
			// 弾の読み込み
			var bullet = LoadBullet();

			// 発射地点の設定
			Ray ray = Camera.main.ScreenPointToRay( Input.mousePosition );		// マウス座標を狙うレイを作成

			// 方向確定
			Vector3 dir = ray.direction.normalized;
			
			// 速度設定
			bullet.GetComponent<Rigidbody>().velocity = dir * power;
		}
	}

	GameObject LoadBullet() {
		// 弾オブジェクトの生成
		var bullet = GameObject.Instantiate(prefab);

		// 弾の初期設定
		bullet.transform.parent = transform;
		bullet.transform.localPosition = Vector3.zero;

		// 生成した弾情報を返す
		return bullet;
	}
}
