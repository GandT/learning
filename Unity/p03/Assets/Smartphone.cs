using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Smartphone : MonoBehaviour {

	// 毎フレーム処理
	void Update () {
        if (Application.platform == RuntimePlatform.Android || Application.platform == RuntimePlatform.IPhonePlayer)
        {
            // スマートフォンの重力を取得（varで型指定不要）
            var direction = Input.acceleration;

            // z方向加速度を無視
            direction.z = 0;

            // 重力を正規化した重力方向に変換
            Vector3 v = direction.normalized;
            Physics.gravity = v;

            // 変換後の重力に従った計算は他のどこかでやってくれる模様
        }
	}
}
