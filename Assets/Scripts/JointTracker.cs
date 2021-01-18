using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class JointTracker : MonoBehaviour
{
    // List of all of the DH parameters we can control
    static public List<double> a     = new List<double>(){0.0};
    static public List<double> alpha = new List<double>(){0.0};
    static public List<double> d     = new List<double>(){0.0};
    static public List<double> theta = new List<double>(){0.0};

    public GameObject FramePrefab;
    public GameObject GuiPrefab;
    public GameObject ControlPrefab;

    public GameObject CanvasObject;
    public GameObject ControlObject;

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

    public void RunDynamics(){
        // DynamicsClientHandler.RunDynamics(a,alpha,d,theta);
        string aString     = string.Join( ",", a);
        string alphaString = string.Join( ",", alpha);
        string dString     = string.Join( ",", d);
        string thetaString = string.Join( ",", theta);
        string all_params = aString + " " + alphaString + " " + dString + " " + thetaString;
        Process foo = new Process();
        foo.StartInfo.FileName = "python_dh_dynamics.exe";
        foo.StartInfo.Arguments = all_params;
        foo.Start();
    }

    // public void StartClient(){
    //     DynamicsClientHandler.SpawnClient();
    // }

    public void AddJoint(){
        // var CanvasObject   = GameObject.Find("UI");
        var FrameObject    = GameObject.Find("Frame" + num_joints.ToString());
        // var ControlObject  = GameObject.Find("ControlPanel");

        GameObject NewFrame = Instantiate(FramePrefab, new Vector3(0, 0, 0), Quaternion.identity);
        GameObject NewGui = Instantiate(GuiPrefab, new Vector3(200, -100 - num_joints*150, 0), Quaternion.identity);
        GameObject NewControl = Instantiate(ControlPrefab, new Vector3(110, -55 - (num_joints-1)*50, 0), Quaternion.identity);

        NewGui.transform.SetParent(CanvasObject.transform);
        NewFrame.transform.SetParent(FrameObject.transform);
        NewControl.transform.SetParent(ControlObject.transform);

        RectTransform guiRT     = NewGui.GetComponent<RectTransform>();
        RectTransform controlRT = NewControl.GetComponent<RectTransform>();

        // NewGui.transform.localPosition = new Vector3(200, -100 - num_joints*150, 0);
        guiRT.anchoredPosition = new Vector3(200, -100 - (num_joints)*150, 0);
        guiRT.localScale = new Vector3(1,1,1);
        controlRT.anchoredPosition = new Vector3(110, -55 - (num_joints-1)*50, 0);
        controlRT.localScale = new Vector3(1,1,1);

        NewFrame.transform.localPosition = new Vector3(0, 0, 0);
        NewFrame.transform.localRotation = Quaternion.identity;

        num_joints++;

        NewFrame.transform.name = "Frame" +  num_joints.ToString();
        NewGui.transform.name = "Joint" +  num_joints.ToString();
        NewControl.transform.name = "Control" +  (num_joints-1).ToString();

        NewGui.transform.Find("Text").Find("JointName").GetComponent<TextMeshProUGUI>().text = "Joint " + num_joints.ToString() + ":";

        NewControl.transform.Find("tauText").GetComponent<TextMeshProUGUI>().text = "τ<sub>" + (num_joints-1).ToString() + "</sub>";
        NewControl.transform.Find("qText").GetComponent<TextMeshProUGUI>().text =  "q<sub>" + (num_joints-1).ToString() + "</sub>";

        ControlObject.GetComponent<RectTransform>().sizeDelta = new Vector2(400,80+50*(num_joints-2));
        ControlObject.GetComponent<RectTransform>().anchoredPosition = new Vector3(-200,-150 - 25*(num_joints-2),0);

        // update the DH parameters by adding another list entry
        a.Add(0);
        alpha.Add(0);
        d.Add(0);
        theta.Add(0);
    }

    public void RemoveJoint(){
        var LastGui = GameObject.Find("Joint" + num_joints.ToString());
        var LastFrame  = GameObject.Find("Frame" + num_joints.ToString());
        var LastControl  = GameObject.Find("Control" + num_joints.ToString());
        Destroy(LastGui);
        Destroy(LastFrame);
        Destroy(LastControl);

        num_joints--;

        GameObject ControlObject = GameObject.Find("ControlPanel");
        ControlObject.GetComponent<RectTransform>().sizeDelta = new Vector2(400,80+50*(num_joints-2));
        ControlObject.GetComponent<RectTransform>().anchoredPosition = new Vector3(-200,-150 - 25*(num_joints-2),0);

        // update the DH parameters by removing the last list entry
        a.RemoveAt(a.Count-1);
        alpha.RemoveAt(a.Count-1);
        d.RemoveAt(a.Count-1);
        theta.RemoveAt(a.Count-1);
    }
}
