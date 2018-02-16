// Copyright (c) 2017-2018 Scash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "blockexplorerstyle.h"

namespace BlockExplorer
{

std::string Style::getStyleData()
{
    return (std::string) "body{background: #fff; font: 12px Lucida sans, Arial, Helvetica, sans-serif;color: #333;} " +
            " a{color: #2A679F;}.form-wrapper{background-color: #f6f6f6;background-image: -webkit-gradient(linear, left top, left bottom, from(#f6f6f6), to(#eae8e8));background-image: -webkit-linear-gradient(top, #f6f6f6, #eae8e8);background-image: -moz-linear-gradient(top, #f6f6f6, #eae8e8);background-image: -ms-linear-gradient(top, #f6f6f6, #eae8e8);background-image: -o-linear-gradient(top, #f6f6f6, #eae8e8);background-image: linear-gradient(top, #f6f6f6, #eae8e8);border-color: #dedede #bababa #aaa #bababa;border-style: solid;border-width: 1px;-webkit-border-radius: 10px;-moz-border-radius: 10px;border-radius: 10px;-webkit-box-shadow: 0 3px 3px rgba(255,255,255,.1), 0 3px 0 #bbb, 0 4px 0 #aaa, 0 5px 5px #444;-moz-box-shadow: 0 3px 3px rgba(255,255,255,.1), 0 3px 0 #bbb, 0 4px 0 #aaa, 0 5px 5px #444;box-shadow: 0 3px 3px rgba(255,255,255,.1), 0 3px 0 #bbb, 0 4px 0 #aaa, 0 5px 5px #444;margin:30px auto;overflow: hidden;padding: 8px;width: 780px;}"
            + " .form-wrapper #search{border: 1px solid #CCC;-webkit-box-shadow: 0 1px 1px #ddd inset, 0 1px 0 #FFF;-moz-box-shadow: 0 1px 1px #ddd inset, 0 1px 0 #FFF;box-shadow: 0 1px 1px #ddd inset, 0 1px 0 #FFF;-webkit-border-radius: 3px;-moz-border-radius: 3px;border-radius: 3px; color: #999;float: left;font: 16px Lucida Sans, Trebuchet MS, Tahoma, sans-serif;height: 40px;padding: 10px;width: 650px;}"
            + " .form-wrapper #search:focus{border-color: #aaa;-webkit-box-shadow: 0 1px 1px #bbb inset;-moz-box-shadow: 0 1px 1px #bbb inset;box-shadow: 0 1px 1px #bbb inset;outline: 0;}.form-wrapper #search:-moz-placeholder,.form-wrapper #search:-ms-input-placeholder,.form-wrapper #search::-webkit-input-placeholder{color: #999;font-weight: normal;}"
            + " .form-wrapper #submit{background-color: #0483a0;background-image: -webkit-gradient(linear, left top, left bottom, from(#31b2c3), to(#0483a0));background-image: -webkit-linear-gradient(top, #31b2c3, #0483a0);background-image: -moz-linear-gradient(top, #31b2c3, #0483a0);background-image: -ms-linear-gradient(top, #31b2c3, #0483a0);background-image: -o-linear-gradient(top, #31b2c3, #0483a0);background-image: linear-gradient(top, #31b2c3, #0483a0);border: 1px solid #00748f;-moz-border-radius: 3px;-webkit-border-radius: 3px;border-radius: 3px;-webkit-box-shadow: 0 1px 0 rgba(255, 255, 255, 0.3) inset, 0 1px 0 #FFF;-moz-box-shadow: 0 1px 0 rgba(255, 255, 255, 0.3) inset, 0 1px 0 #FFF;box-shadow: 0 1px 0 rgba(255, 255, 255, 0.3) inset, 0 1px 0 #FFF;color: #fafafa;cursor: pointer;height: 42px;float: right;font: 15px Arial, Helvetica;color: #fff;padding: 0;text-transform: uppercase;text-shadow: 0 1px 0 rgba(0, 0 ,0, .3);width: 100px;}"
            + " .form-wrapper #submit:hover,.form-wrapper #submit:focus{background-color: #31b2c3;background-image: -webkit-gradient(linear, left top, left bottom, from(#0483a0), to(#31b2c3));background-image: -webkit-linear-gradient(top, #0483a0, #31b2c3);background-image: -moz-linear-gradient(top, #0483a0, #31b2c3);background-image: -ms-linear-gradient(top, #0483a0, #31b2c3);background-image: -o-linear-gradient(top, #0483a0, #31b2c3);background-image: linear-gradient(top, #0483a0, #31b2c3);}.form-wrapper #submit:active{-webkit-box-shadow: 0 1px 4px rgba(0, 0, 0, 0.5) inset;-moz-box-shadow: 0 1px 4px rgba(0, 0, 0, 0.5) inset;box-shadow: 0 1px 4px rgba(0, 0, 0, 0.5) inset;outline: 0;}.form-wrapper #submit::-moz-focus-inner{border: 0;} ul { list-style-type: none; padding-left:0; } label{ background-color: #AAAFAB; border-radius: 5px; padding: 3px; padding-left: 25px; color: white; }"
            + " li {  margin: 0px; padding: 5px; border-radius: 5px; } input[type=checkbox] { display: none; } input[type=checkbox] ~ ul { margin-top: 4px; max-height: 0; max-width: 0; opacity: 0; overflow: hidden; white-space:nowrap; -webkit-transition:all 200ms ease;  -moz-transition:all 200ms ease;  -o-transition:all 200ms ease;  transition:all 200ms ease; } "
            + " input[type=checkbox]:checked ~ ul {  max-height: 100%; max-width: 100%; opacity: 1; } input[type=checkbox] + label:before{ transform-origin:25% 50%; border: 7px solid transparent; border-width: 7px 12px;	 border-left-color: white; margin-left: -20px; width: 0; height: 0; display: inline-block; text-align: center; content: ''; color: #AAAFAB; -webkit-transition:all .5s ease;   -moz-transition:all .5s ease;   -o-transition:all .5s ease;   transition:all .5s ease;  position: absolute; margin-top: 1px; } "
            + " input[type=checkbox]:checked + label:before { transform: rotate(90deg); }"
            + " table a:link {color: #666;font-weight: bold;text-decoration:none; } table a:visited { color: #999999; font-weight:bold; text-decoration:none; } table a:active, table a:hover { color: #bd5a35; text-decoration:underline; } "
            + " table { margin-left: auto; margin-right: auto; color:#666; font-size:12px; background:#eaebec; border:#ccc 1px solid; -moz-border-radius:3px; -webkit-border-radius:3px; border-radius:3px; -moz-box-shadow: 0 1px 2px #d1d1d1; -webkit-box-shadow: 0 1px 2px #d1d1d1; box-shadow: 0 1px 2px #d1d1d1; } table th { padding:18px 22px 19px 22px; border-top:1px solid #fafafa; border-bottom:1px solid #e0e0e0; background: #ededed; background: -webkit-gradient(linear, left top, left bottom, from(#ededed), to(#ebebeb)); background: -moz-linear-gradient(top,  #ededed,  #ebebeb); } table th:first-child { text-align: left; padding-left:20px; } "
            + " table tr:first-child th:first-child { -moz-border-radius-topleft:3px; -webkit-border-top-left-radius:3px; border-top-left-radius:3px; } table tr:first-child th:last-child { -moz-border-radius-topright:3px; -webkit-border-top-right-radius:3px; border-top-right-radius:3px; } table tr { text-align: center; padding-left:20px; } table td:first-child { text-align: left; padding-left:20px; border-left: 0; } table td { padding:10px; border-top: 1px solid #ffffff; border-bottom:1px solid #e0e0e0; border-left: 1px solid #e0e0e0; background: #fafafa; background: -webkit-gradient(linear, left top, left bottom, from(#fbfbfb), to(#fafafa)); background: -moz-linear-gradient(top,  #fbfbfb,  #fafafa); } table tr.even td { background: #f6f6f6; background: -webkit-gradient(linear, left top, left bottom, from(#f8f8f8), to(#f6f6f6)); background: -moz-linear-gradient(top,  #f8f8f8,  #f6f6f6); } table tr:last-child td { border-bottom:0; } "
            + " table tr:last-child td:first-child { -moz-border-radius-bottomleft:3px; -webkit-border-bottom-left-radius:3px; border-bottom-left-radius:3px; } table tr:last-child td:last-child { -moz-border-radius-bottomright:3px; -webkit-border-bottom-right-radius:3px; border-bottom-right-radius:3px; } table tr:hover td { background: #f2f2f2; background: -webkit-gradient(linear, left top, left bottom, from(#f2f2f2), to(#f0f0f0)); background: -moz-linear-gradient(top,  #f2f2f2,  #f0f0f0); } "
            + ".col-md-2,.col-md-3{width:140px;position:relative;min-height:1px;padding-left:15px;padding-right:15px}.text-center{text-align:center;}"
            + ".panel-body{border-bottom:1px solid #dddddd}.panel-default{border-color:#dddddd}.panel-default>.panel-heading{color:#333333;background-color:#f5f5f5;border-color:#dddddd}.panel-default>.panel-heading+.panel-collapse>.panel-body{border-top-color:#dddddd}.panel-default>.panel-heading .badge{color:#f5f5f5;background-color:#333333}.panel-default>.panel-footer+.panel-collapse>.panel-body{border-bottom-color:#dddddd}.panel-primary{border-color:#008cba}.panel-primary>.panel-heading{color:#ffffff;background-color:#008cba;border-color:#008cba}.panel-primary>.panel-heading+.panel-collapse>.panel-body{border-top-color:#008cba}.panel-primary>.panel-heading .badge{color:#008cba;background-color:#ffffff}.panel-primary>.panel-footer+.panel-collapse>.panel-body{border-bottom-color:#008cba}.panel-success{border-color:#3c9a5f}.panel-success>.panel-heading{color:#ffffff;background-color:#43ac6a;border-color:#3c9a5f}.panel-success>.panel-heading+.panel-collapse>.panel-body{border-top-color:#3c9a5f}.panel-success>.panel-heading .badge{color:#43ac6a;background-color:#ffffff}.panel-success>.panel-footer+.panel-collapse>.panel-body{border-bottom-color:#3c9a5f}.panel-info{border-color:#3db5d8}.panel-info>.panel-heading{color:#ffffff;background-color:#5bc0de;border-color:#3db5d8}.panel-info>.panel-heading+.panel-collapse>.panel-body{border-top-color:#3db5d8}.panel-info>.panel-heading .badge{color:#5bc0de;background-color:#ffffff}.panel-info>.panel-footer+.panel-collapse>.panel-body{border-bottom-color:#3db5d8}.panel-warning{border-color:#d08002}.panel-warning>.panel-heading{color:#ffffff;background-color:#e99002;border-color:#d08002}.panel-warning>.panel-heading+.panel-collapse>.panel-body{border-top-color:#d08002}.panel-warning>.panel-heading .badge{color:#e99002;background-color:#ffffff}.panel-warning>.panel-footer+.panel-collapse>.panel-body{border-bottom-color:#d08002}.panel-danger{border-color:#ea2f10}.panel-danger>.panel-heading{color:#ffffff;background-color:#f04124;border-color:#ea2f10}.panel-danger>.panel-heading+.panel-collapse>.panel-body{border-top-color:#ea2f10}.panel-danger>.panel-heading .badge{color:#f04124;background-color:#ffffff}.panel-danger>.panel-footer+.panel-collapse>.panel-body{border-bottom-color:#ea2f10}"
            ;
}

std::string Style::getStyleInline()
{
    return "<style>" + getStyleData() + "</style>";
}

std::string Style::getStyleCssFileContent()
{
    return getStyleData();
}

std::string Style::getStyleCssFileName()
{
    return "mystyle.css";
}

std::string Style::getStyleCssLink()
{
    return "<link REL=\"StyleSheet\" TYPE=\"text/css\" HREF=\"" + getStyleCssFileName() + "\">";
}

}
