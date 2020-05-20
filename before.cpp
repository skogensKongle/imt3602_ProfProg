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


	// Start is called before the first frame update
	void Start()
	{
		currentID = 0;
		currentObject = null;
		clickUI.AddOnStateDownListener(triggerDown, handType);
	}

	// Update is called once per frame
	void Update()
	{
		//Sends raycast and fills array with all it hits
		RaycastHit[] hits;
		hits = Physics.RaycastAll(transform.position, transform.forward, 10f);

		//Goes through array and check if any are buttons
		for(int i = 0; i < hits.Length; i++)
		{
			RaycastHit hit = hits[i];

			//Using id to check if object is allready checked
			int id = hit.collider.gameObject.GetInstanceID();

			//if its not current id then i will check it
			if(currentID != id)
			{
				currentID = id;
				currentObject = hits[0].collider.gameObject;

				//checkes based on tag
				string tag = currentObject.tag;
				if (tag == "Button")
				{
					Debug.Log("This is a button!");
					Debug.Log(hits[0].collider.gameObject.name);
					clickUI.AddOnStateDownListener(triggerDown, handType);
				}
			}
		}


	}

	public void triggerDown(SteamVR_Action_Boolean fromAction, SteamVR_Input_Sources fromSource)
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