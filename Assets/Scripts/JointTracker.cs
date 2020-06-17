﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class JointTracker : MonoBehaviour
{
    // List of all of the DH parameters we can control
    static public List<float> a     = new List<float>();
    static public List<float> alpha = new List<float>();
    static public List<float> d     = new List<float>();
    static public List<float> theta = new List<float>();

    public GameObject FramePrefab;
    public GameObject GuiPrefab;

    static public int num_joints;
    // Start is called before the first frame update
    void Start()
    {
        num_joints = 1;        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void AddJoint(){
        var CanvasObject = GameObject.Find("Canvas");
        var FrameObject  = GameObject.Find("Frame" + num_joints.ToString());

        GameObject NewFrame = Instantiate(FramePrefab, new Vector3(0, 0, 0), Quaternion.identity);
        GameObject NewGui = Instantiate(GuiPrefab, new Vector3(200, -100 - num_joints*150, 0), Quaternion.identity);

        NewGui.transform.SetParent(CanvasObject.transform);
        NewFrame.transform.SetParent(FrameObject.transform);

        RectTransform rt = NewGui.GetComponent<RectTransform>();

        // NewGui.transform.localPosition = new Vector3(200, -100 - num_joints*150, 0);
        rt.anchoredPosition = new Vector3(200, -100 - (num_joints)*150, 0);
        NewFrame.transform.localPosition = new Vector3(0, 0, 0);

        num_joints++;

        NewFrame.transform.name = "Frame" +  num_joints.ToString();
        NewGui.transform.name = "Joint" +  num_joints.ToString();

        NewGui.transform.Find("Text").Find("JointName").GetComponent<Text>().text = "Joint " + num_joints.ToString() + ":";

        // update the DH parameters by adding another list entry
        a.Add(0);
        alpha.Add(0);
        d.Add(0);
        theta.Add(0);
    }

    public void RemoveJoint(){
        var LastGui = GameObject.Find("Joint" + num_joints.ToString());
        var LastFrame  = GameObject.Find("Frame" + num_joints.ToString());
        Destroy(LastGui);
        Destroy(LastFrame);

        num_joints--;

        // update the DH parameters by removing the last list entry
        a.RemoveAt(a.Count-1);
        alpha.RemoveAt(a.Count-1);
        d.RemoveAt(a.Count-1);
        theta.RemoveAt(a.Count-1);
    }
}