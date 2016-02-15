VCL.recv do |conf|
  return VCL::Action::Pass if conf.req.http.host == "example.com" || conf.req.url == "^/admin" || conf.req.http.Cookie == "logged_in"
   conf.req.http.Cookie = nil
end
