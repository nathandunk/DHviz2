using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SliderScript : MonoBehaviour
{
    float a;
    float alpha;
    float d;
    float theta;

    string curr_slider;
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setA(){curr_slider = "a";}
    public void setAlpha(){curr_slider = "alpha";}
    public void setD(){curr_slider = "d";}
    public void setTheta(){curr_slider = "theta";}

    public void slider_change(float value)
    {
        // var current_name = gameObject.transform.name;
        var name = gameObject.transform.name;
        var result = name.Substring(name.Length - 1);
        
        var frame = GameObject.Find("Frame" + result);

        var current_position = frame.transform.localPosition;
        var current_angles   = frame.transform.localEulerAngles;
        
        switch (curr_slider)
        {
            case "a":
                // frame.transform.localPosition = new Vector3(value,current_position.y,current_position.z);
                a = value/Constants.scale_factor;
                break;
            case "alpha":
                // frame.transform.localEulerAngles = new Vector3(value,current_angles.y,current_angles.z);
                alpha = value/Constants.scale_factor;
                break;
            case "d":
                // frame.transform.localPosition = new Vector3(current_position.x,value,current_position.z);
                d = value/Constants.scale_factor;
                break;
            case "theta":
                // frame.transform.localEulerAngles = new Vector3(current_angles.x,-value,current_angles.z);
                theta = value/Constants.scale_factor;
                break;
            default:
                break;
        }

        frame.transform.localPosition = new Vector3(a,d,0);
        frame.transform.localRotation = Quaternion.AngleAxis(-alpha,Vector3.right)*Quaternion.AngleAxis(-theta, Vector3.up);
    }
}
