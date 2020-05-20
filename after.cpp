using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Valve.VR;
using Valve.VR.Extras;
using Valve.VR.InteractionSystem;

public class ButtonClicking : MonoBehaviour
{

	//reference to action
	public SteamVR_Action_Boolean clickUI;

	//reference to hand
	public SteamVR_Input_Sources handType;


	public static GameObject currentObject;
	int currentID;



	void Start()
	{
		currentID = 0;
		currentObject = null;
		clickUI.AddOnStateDownListener(triggerDown, handType);
	}

	//Triggers button click if pointed to gameobject was a button.
	public void triggerDown(SteamVR_Action_Boolean fromAction, SteamVR_Input_Sources fromSource)
	{

		Ray raycast = new Ray(transform.position, transform.forward);
		RaycastHit hit;
		bool bHit = Physics.Raycast(raycast, out hit);

		if (bHit)
		{
			currentObject = hit.collider.gameObject;

			if (currentObject.tag == "Button")
			{
				Debug.Log("Button is clicked");
				Debug.Log(currentObject.name);
				currentObject.GetComponent<Button>().onClick.Invoke();
			}
		}


	}
