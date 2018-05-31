if (Math.random() < 0.2) {
    window.location.href = "http://www.wangyulin.cc";
}
var regSessionId = new RegExp("^[A-za-z0-9=/+]{16,}$");
var regScore = new RegExp("^[0-9]{1,}$");
$(document).ready(function() {
    var resultP = $(".result>p");
    $("#submit").click(function() {
            var sessionId = $("input#sessionId").val();
            var score = $("input#score").val();
            sessionId.replace("\u003d", "=");

            function showResultP() {
                resultP.attr("class", "text-warning");
                resultP.show();
                return false;
            }

            if (!regSessionId.test(sessionId)) {
                resultP.text("session_id 格式有误，session_id中不应当有冒号，而是两个冒号中间的字符串");
                return showResultP();
            }
            if (!regScore.test(score)) {
                resultP.text("分数格式有误");
                return showResultP();
            }
            if (score > 1000) {
                resultP.text("分数大于1000刷不上，且会被封号");
                return showResultP();
            }
            $.ajax({
                type: "POST",
                url: "Wxtyt",
                dateType: "text/plain",
                data: {
                    sessionID: sessionId,
                    score: score,
                },
                beforeSend: function() {
                    resultP.text("提交中...")
                    resultP.attr("class", "text-warning");
                    $(".result>p").show();
                },
                success: function(result, textStatus) {
                    if (textStatus == "success") {


                        var data = result.TecentInfo;
                        var lastInfo = result.myUserInfo;

                        var explain = "未知";
                        var resultClass = "text-warning";
                        var errcode = data.base_resp.errcode;
                        var dataStr = JSON.stringify(data);
                        if (errcode != undefined) {
                            switch (errcode) {
                                case 0:
                                    explain = "数据提交成功";
                                    resultClass = "text-success";
                                    break;
                                case -1:
                                    explain = "session_id无效";
                                    break;
                                case 108:
                                    explain = "发出的参数有误或分数大于1000分，频繁出现此错误可能是凉了。";
                                    break;
                                case -5:
                                    explain = "session_id过期，需要重新获取";
                                    break;
                                case -2:
                                    explain = "数据组织的有错误，检查下session_id是不是复制错了，正常session_id中不应当有冒号,而是两个冒号中间的字符串";
                                    break;
                                default:
                                    explain = "未知错误"
                                    break;
                            }
                        }
                        resultP.html("腾讯服务器返回的原始数据: <br />" + dataStr + "<br />代表含义：" + explain);
                        resultP.attr("class", resultClass);
                        resultP.show();
                        if (lastInfo != undefined && lastInfo.week_best_score != undefined) {
                            var imgUrl = lastInfo.headimg;
                            var score = lastInfo.week_best_score;
                            var nickName = lastInfo.nickname;
                            $(".user_info>img").attr("src", imgUrl);
                            $(".nickName").text(nickName);
                            $(".score").text(score);
                            $(".user_info").show();
                        }
                    }
                },
                error: function(data, textStatus) {
                    resultP.text("服务器出错");
                    resultP.attr("class", "text-danger");
                    resultP.show();
                },
                complete: function(XMLHttpRequest, textStatus) {}
            })
        })
        /* $.ajax({
             type:"POST",
             url:"LastSuccess",
             dateType:"application/json",
             beforeSend: function () {
                 $(".lastSuccessTime>span").text("获取中...");
             },
             success: function (data, textStatus) {
                 if (textStatus == "success") {
                     $(".lastSuccessTime>span").text(data.lastTime);
                 }
             },
             error: function (data, textStatus) {
                 resultP.text("服务器出错");
                 resultP.attr("class", "text-danger");
                 resultP.show();
             },
             complete: function (XMLHttpRequest, textStatus) {
             }
         })*/
})