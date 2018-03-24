using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyController : MonoBehaviour {

	[SerializeField] float lifetime = 0;

	void Start () {
		Destroy(gameObject, lifetime);
	}
}
