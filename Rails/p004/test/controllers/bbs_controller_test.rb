require 'test_helper'

class BbsControllerTest < ActionDispatch::IntegrationTest
  test "should get index" do
    get bbs_index_url
    assert_response :success
  end

end
