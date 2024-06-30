--- infrastructure/os/limits/limits_unix.go.orig	2024-05-09 15:53:21 UTC
+++ infrastructure/os/limits/limits_unix.go
@@ -22,23 +22,23 @@ func SetLimits(desiredLimits *DesiredLimits) error {
 	if err != nil {
 		return err
 	}
-	if rLimit.Cur > desiredLimits.FileLimitWant {
+	if int64(rLimit.Cur) > int64(desiredLimits.FileLimitWant) {
 		return nil
 	}
-	if rLimit.Max < desiredLimits.FileLimitMin {
+	if int64(rLimit.Max) < int64(desiredLimits.FileLimitMin) {
 		err = errors.Errorf("need at least %d file descriptors",
 			desiredLimits.FileLimitMin)
 		return err
 	}
-	if rLimit.Max < desiredLimits.FileLimitWant {
+	if int64(rLimit.Max) < int64(desiredLimits.FileLimitWant) {
 		rLimit.Cur = rLimit.Max
 	} else {
-		rLimit.Cur = desiredLimits.FileLimitWant
+		rLimit.Cur = int64(desiredLimits.FileLimitWant)
 	}
 	err = syscall.Setrlimit(syscall.RLIMIT_NOFILE, &rLimit)
 	if err != nil {
 		// try min value
-		rLimit.Cur = desiredLimits.FileLimitMin
+		rLimit.Cur = int64(desiredLimits.FileLimitMin)
 		err = syscall.Setrlimit(syscall.RLIMIT_NOFILE, &rLimit)
 		if err != nil {
 			return err
