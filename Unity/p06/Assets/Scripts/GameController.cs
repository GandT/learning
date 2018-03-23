using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameController : MonoBehaviour {

	[SerializeField] GameObject hazard = null;
	[SerializeField] Vector3 spawnValues = new Vector3(6, 0, 16);

	void Start()
	{
		// 初期化

		// 敵を作成
		SpawnWaves();
	}
	

	void Update()
	{
		
	}


	void SpawnWaves()
	{
		Vector3 spawnPosition = new Vector3(Random.Range(-spawnValues.x, spawnValues.x), spawnValues.y, spawnValues.z);
		Quaternion spawnRotation = Quaternion.identity; // 無回転

		Instantiate(hazard, spawnPosition, spawnRotation);
	}
}
