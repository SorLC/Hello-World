using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using DG.Tweening;

public class PausePanel : BasePanel
{
    public bool onAnimEnd = false;
    

    

    public override void OnEnter()
    {
        canvasGroup.blocksRaycasts = true;
        Tween tween = canvasGroup.DOFade(1, 0.2f);

        tween.OnComplete(() => { Time.timeScale = 0; });
    }

    #region button click event

    public void OnClickCloseButton()
    {
        Time.timeScale = 1;
    }

    public void OnClickRestartButton()
    {
        Time.timeScale = 1;
        SceneManager.LoadScene(GameRecord.Instance.currentLevelIndex + 1);
    }

    public void OnClickReturnButton()
    {
        Time.timeScale = 1;
        SceneManager.LoadScene(1);
    }

    

    #endregion

    
}
