using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HitManager : MonoBehaviour {

	Transform _transform;

	[SerializeField] GameObject explosion = null;
	[SerializeField] GameObject playerExplosion = null;
	[SerializeField] int scoreValue = 100;

	GameController gameController = null;
	

	void Start()
	{
		_transform = GetComponent<Transform>();

		// GameControllerへの参照
		GameObject gameControllerObject = GameObject.Find("GameController");
		if(gameControllerObject)gameController = gameControllerObject.GetComponent<GameController>();
		if(!gameController) Debug.Log("GameControllerへの参照が取得できませんでした。");
	}


	//接触時処理
	void OnTriggerEnter(Collider other)
	{
		// システム用オブジェクトは無視する
		if(other.tag == "GameController") return;

		// 爆発エフェクトを表示
		Instantiate(explosion, _transform.position, _transform.rotation);
		if(other.tag == "Player"){
			Instantiate(playerExplosion, other.transform.position, other.transform.rotation);
			// ゲームオーバー処理
			gameController.Gameover();
		}

		// スコア計算
		gameController.AddScore(scoreValue);

		// 相手を破壊
		Destroy(other.gameObject);
		// 自分を破壊
		Destroy(gameObject);
	}
}
