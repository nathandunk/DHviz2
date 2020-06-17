using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.UI;
using System.Globalization;

public class ConnectSliderText : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void updateSliderFromText(string text){
        float text_float = float.Parse(text, CultureInfo.InvariantCulture.NumberFormat);
        
        string text_name = gameObject.transform.name;
        string slider_name = text_name.Substring(0,text_name.Length-6);

        Slider slider_object = gameObject.transform.parent.Find(slider_name).GetComponent<Slider>();
        if(slider_object.value != text_float*Constants.scale_factor){
            slider_object.value = text_float*Constants.scale_factor;
        }
    }

    public void updateTextFromSlider(float value){
        string value_string = (value/Constants.scale_factor).ToString();
        
        string slider_name = gameObject.transform.name;
        string text_name = slider_name + "_input";

        InputField text_object = gameObject.transform.parent.Find(text_name).GetComponent<InputField>();
        if (!String.Equals(value_string,text_object.text)){
            text_object.text = value_string;
        }
    }
}
