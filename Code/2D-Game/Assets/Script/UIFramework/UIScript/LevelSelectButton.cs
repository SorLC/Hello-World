﻿using UnityEngine;
using UnityEngine.SceneManagement;

public class LevelSelectButton : MonoBehaviour
{
    public int buttonLevelIndex = 1;

    private Transform outline;
    private Transform outline_Passed;
    private Transform lockPanel;
    private Transform playerImage;
    private Transform specialCoinPanel;
    [HideInInspector]
    public Transform[] specialCoin;


    private float radian = 0; //漂浮动画弧度增量

    private void Awake()
    {
        outline = transform.Find("outline");
        outline_Passed = transform.Find("outline_Passed");
        lockPanel = transform.Find("lockPanel");
        playerImage = transform.Find("Player");
        specialCoinPanel = transform.Find("SpecialCoin");

        if (GameRecord.Instance.beingPassedLevel >= buttonLevelIndex)
        {
            //if (GameRecord.Instance.currentLevelIndex == buttonLevelIndex)
            //    SetUIActive(outline_Passed: true);
            //else
            SetUIActive(outline_Passed: true);
            if (GameRecord.Instance.currentLevelIndex == buttonLevelIndex)
            {
                SetUIActive(outline: true);
            }
        }
        //else if (GameRecord.Instance.beingPassedLevel == buttonLevelIndex)
        //{  
        //        SetUIActive(outline: true); 
        //}
        else
        {
            SetUIActive(lockPanel: true);
        }


        
    }

    private void Update()
    {
        if (GameRecord.Instance.beingPassedLevel == buttonLevelIndex)
        {
            OutlineAnim();
        }
        ButtonAnim();
    }

    private void OutlineAnim()
    {
        if (outline.gameObject.activeSelf == true)
        {
            Transform temp = outline.transform;
            temp.transform.Rotate(Vector3.back, Time.deltaTime * 15f);
            outline.transform.rotation = temp.rotation;
        }
    }

    private void ButtonAnim()
    {
        Vector3 temp = transform.localPosition;

        radian += 1f * Time.deltaTime;
        temp.y = Mathf.Sin(radian + buttonLevelIndex) * 20f;

        transform.localPosition = temp;
    }

    private void SetUIActive(bool outline = false, bool outline_Passed = false, bool lockPanel = false)
    {
        this.outline.gameObject.SetActive(outline);
        this.outline_Passed.gameObject.SetActive(outline_Passed);
        this.lockPanel.gameObject.SetActive(lockPanel);
        //playerImage.gameObject.SetActive(player);
        //this.specialCoinPanel.gameObject.SetActive(specialCoinPanel);
    }

    public void OnClickLevelSelectButton()
    {       
        if (buttonLevelIndex <= GameRecord.Instance.beingPassedLevel)
        {
            GameRecord.Instance.currentLevelIndex = buttonLevelIndex;
            GameRecord.Instance.Save(GameRoot.GameRecordJsonSavePath);
            SceneManager.LoadScene(buttonLevelIndex + 1);
        }
    }
}
