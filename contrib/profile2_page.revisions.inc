<?php

function profile2_revisions_view_for_user($type, $account = NUll) {
  if ($account) {
    $uid = $account->uid;
  }
  else {
    global $user;
    $uid = $user->uid;
  }
  return profile2_revision_overview(profile2_by_uid_load($uid, $type));
}